from django.shortcuts import redirect
from django.template import loader
from django.http import HttpRequest as req
from django.http import HttpResponse as http_resp
from django.core.exceptions import ValidationError
from .validators import NameValidator, UsernameValidator
from django.contrib.auth.password_validation import validate_password
from django.contrib.auth.hashers import make_password, check_password
from django.views.decorators.http import require_POST as req_post
from .models import User, Friend
from game.models import Match, Tournament
from django.conf import settings
from pathlib import Path
from .utils import error_to_dict, build_url, load_template, is_logged_in, get_session, activate_lang
import json, requests
import contextlib
import os
import pyotp
import qrcode
import base64
from io import BytesIO
from rest_framework_simplejwt.tokens import RefreshToken
from PIL import Image
from django.utils import translation
from django.db.models import Q

root: Path = settings.BASE_DIR / 'control'
templates_path: Path = root / 'templates'
pages_path: Path = templates_path / 'pages'

# Create your views here.
@req_post
def sign_up(request: req) -> http_resp:
    if is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_out"))), status=401)
    fname_validator: NameValidator = NameValidator(description=translation.gettext("description_first_name"))
    lname_validator: NameValidator = NameValidator(description=translation.gettext("description_last_name"))
    username_validator: UsernameValidator = UsernameValidator()
    try:
        fname_validator(request.POST['first_name'])
        lname_validator(request.POST['last_name'])
        username_validator(request.POST['username'])
        if User.objects.filter(username=request.POST['username']).exists():
            raise ValidationError(translation.gettext("logs_error_user_already_exists"))
        validate_password(request.POST['password'])
        profile_image = None
        try:
            profile_image = request.FILES['profile_image']
        except:
            pass
        if request.POST['password'] != request.POST['confirm_password']:
            raise ValidationError(translation.gettext("logs_error_password_dont_match"))
        if profile_image:
            try:
                Image.open(profile_image).verify()
            except:
                raise ValidationError(translation.gettext("logs_error_image_invalid_upload"))
        if not request.POST.get('accept_terms'):
            raise ValidationError(translation.gettext("logs_error_need_accept_terms"))
        user: User = User.objects.create(first_name=request.POST['first_name'],
                                         last_name=request.POST['last_name'],
                                         username=request.POST['username'],
                                         password=make_password(request.POST['password']),
                                         profile_image=profile_image,
                                         lang=request.session.get('lang', settings.LANGUAGE_CODE),
                                         null_password=False)
        translation.activate(user.lang)
        session_token = RefreshToken.for_user(user)
        request.session['username'] = user.username
        request.session['session_token'] = str(session_token)
        json_data = {'title': translation.gettext('main_profile'),
                     'status': translation.gettext('logs_success_user_signed_up %(username)s') % {'username': request.POST['username']}}
        return http_resp(content=json.dumps(obj=json_data), status=201)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def sign_out(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        user: User = User.objects.filter(username=request.session['username']).first()
        del request.session['username']
        del request.session['session_token']
        json_data = {'title': 'Transcendence',
                     'status': translation.gettext('logs_success_user_signed_out %(username)s') % {'username': user.username}}
        return http_resp(content=json.dumps(obj=json_data), status=200)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def sign_in(request: req) -> http_resp:
    if is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_out"))), status=401)
    try:
        user: User = User.objects.filter(username=request.POST['username']).first()
        if not user:
            raise ValidationError(translation.gettext('logs_error_user_not_found %(username)s') % {'username': request.POST['username']})
        if user.null_password:
            raise ValidationError(translation.gettext("logs_error_user_no_password"))
        if not check_password(request.POST['password'], user.password):
            raise ValidationError(translation.gettext('logs_error_password_wrong %(username)s') % {'username': request.POST['username']})
        session_token = RefreshToken.for_user(user)
        request.session['username'] = user.username
        request.session['session_token'] = str(session_token)
        if user.two_fa:
            request.session['two_fa_required'] = True
        json_data = {'title': translation.gettext('main_profile'),
                     'status': translation.gettext('logs_success_user_signed_in %(username)s') % {'username': user.username}}
        return http_resp(content=json.dumps(obj=json_data), status=200)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def sign_with_ft(request: req) -> http_resp:
    if is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_out"))), status=401)
    authorization_url = build_url(protocol='https',
                                  domain='42.fr',
                                  subdomain='api.intra',
                                  route='oauth/authorize',
                                  query_params={'client_id': settings.CLIENT_ID,
                                                'redirect_uri': settings.REDIRECT_URI,
                                                'response_type': 'code',
                                                'scope': ' '.join(['public', 'profile', 'elearning', 'tig'])})
    return http_resp(content=json.dumps(obj={'authorization_url': authorization_url}), status=200)

def callback(request: req) -> http_resp:
    code: str = request.GET.get('code')
    if not code:
        return redirect(to='/')
    with contextlib.suppress(Exception):
        handle_callback(code, request)
    return redirect(to='/')

def handle_callback(code: str, request: req) -> None:
    token_url = build_url(protocol='https',
                          domain='42.fr',
                          subdomain='api.intra',
                          route='oauth/token')
    token_resp = requests.post(url=token_url,
                               data={'grant_type': 'authorization_code',
                                     'client_id': settings.CLIENT_ID,
                                     'client_secret': settings.CLIENT_SECRET,
                                     'code': code,
                                     'redirect_uri': settings.REDIRECT_URI})
    token_json = token_resp.json()
    access_token = token_json['access_token']
    profile_url = build_url(protocol='https',
                            domain='42.fr',
                            subdomain='api.intra',
                            route='v2/me')
    profile_resp = requests.get(url=profile_url,
                                headers={'Authorization': f'Bearer {access_token}'})
    profile_json = profile_resp.json()
    user: User = User.objects.filter(username=profile_json['login']).first()
    if user is not None:
        update_user_callback(profile_json, user, request)
    else:
        new_user = User.objects.create(first_name=profile_json['first_name'].split()[0],
                                       last_name=profile_json['last_name'].split()[-1],
                                       username=profile_json['login'],
                                       ft_image=profile_json['image']['link'],
                                       lang=request.session.get('lang', settings.LANGUAGE_CODE),
                                       ft_link=True)
        session_token = RefreshToken.for_user(new_user)
        request.session['username'] = new_user.username
        request.session['session_token'] = str(session_token)

def update_user_callback(profile_json: dict, user: User, request: req) -> None:
    user.first_name = profile_json['first_name'].split()[0]
    user.last_name = profile_json['last_name'].split()[-1]
    user.username = profile_json['login']
    user.ft_image = profile_json['image']['link']
    user.ft_link = True
    user.save()
    session_token = RefreshToken.for_user(user)
    request.session['username'] = user.username
    request.session['session_token'] = str(session_token)
    if user.two_fa:
        request.session['two_fa_required'] = True

@req_post
def configure_password(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        user: User = User.objects.filter(username=request.session['username']).first()
        validate_password(request.POST['password'])
        if request.POST['password'] != request.POST['confirm_password']:
            raise ValidationError(translation.gettext("logs_error_password_dont_match"))
        user.password = make_password(request.POST['password'])
        user.null_password = False
        user.save()
        json_data = {'status': translation.gettext('logs_success_password_set')}
        return http_resp(content=json.dumps(obj=json_data), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def content(request: req, page: str) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    user = User.objects.filter(username=request.session['username']).first()
    if not user:
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext('logs_error_user_not_found %(username)s') % {'username': request.session['username']})),
                         status=401)
    if user.null_password:
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_config_pass"))), status=401)
    template_name: str = str(pages_path / f'{page}.html')
    return load_template(request=request, template_name=template_name)

@req_post
def update(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    fname_validator: NameValidator = NameValidator(description=translation.gettext("description_first_name"))
    lname_validator: NameValidator = NameValidator(description=translation.gettext("description_last_name"))
    username_validator: UsernameValidator = UsernameValidator()
    try:
        user: User = User.objects.filter(username=request.session['username']).first()
        if not user.ft_link:
            fname_validator(request.POST['first_name'])
            lname_validator(request.POST['last_name'])
            username_validator(request.POST['username'])
            user.first_name = request.POST['first_name']
            user.last_name = request.POST['last_name']
            if user.username == request.POST['username']:
                pass
            elif User.objects.filter(username=request.POST['username']).exists():
                raise ValidationError(translation.gettext("logs_error_user_already_exists"))
            else:
                matches = Match.objects.filter(user_id=user.id)
                for m in matches:
                    if m.home_player_alias_name == request.session['username']:
                        m.home_player_alias_name = request.POST['username']
                    elif m.away_player_alias_name == request.session['username']:
                        m.away_player_alias_name = request.POST['username']
                    m.save()
                tournaments = Tournament.objects.filter(user_id=user.id)
                for t in tournaments:
                    if t.winner == request.session['username']:
                        t.winner = request.POST['username']
                    t.save()
                user.username = request.POST['username']
            if request.FILES and request.FILES['profile_image']:
                try:
                    Image.open(request.FILES['profile_image']).verify()
                except:
                    raise ValidationError(translation.gettext("logs_error_image_invalid_upload"))
                old_image = user.profile_image
                user.profile_image = request.FILES['profile_image']
                try:
                    os.remove(old_image.path)
                except:
                    pass
        if request.POST['lang'] in dict(settings.LANGUAGES):
            user.lang = request.POST['lang']
        user.anonymous_name = True if request.POST.get('anonymous_name') else False
        if request.POST['new_password']:
            if not check_password(request.POST['old_password'], user.password):
                raise ValidationError(translation.gettext("logs_error_password_wrong_old"))
            validate_password(request.POST['new_password'])
            if request.POST['new_password'] != request.POST['confirm_new_password']:
                raise ValidationError(translation.gettext("logs_error_password_dont_match"))
            if check_password(request.POST['new_password'], user.password):
                raise ValidationError(translation.gettext("logs_error_password_bad_new"))
            user.password = make_password(request.POST['new_password'])
        user.save()
        translation.activate(user.lang)
        request.session['username'] = user.username
        json_data = {'title': translation.gettext('main_profile'),
                     'status': translation.gettext('logs_success_user_updated')}
        return http_resp(content=json.dumps(obj=json_data), status=200)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def enable_two_factor_auth(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        user: User = User.objects.filter(username=request.session['username']).first()
        if user.two_fa:
            raise translation.gettext('logs_error_tfa_already_enabled')
        secret = pyotp.random_base32()
        user.two_fa_secret = secret
        user.save()
        otp_uri = pyotp.totp.TOTP(secret).provisioning_uri(name=user.username, issuer_name="Transcendence")
        qr = qrcode.make(otp_uri)
        buffer = BytesIO()
        qr.save(buffer, format="PNG")
        two_factor_auth_qr_code_base64 = base64.b64encode(buffer.getvalue()).decode('utf-8')
        context = get_session(request)
        context['two_factor_auth_qr_code_base64'] = two_factor_auth_qr_code_base64
        enable_two_factor_auth_modal = loader.render_to_string(request=request,
                                                               context=context,
                                                               template_name=templates_path / 'enable_two_factor_auth_modal.html')
        return http_resp(content=json.dumps(obj={'html': enable_two_factor_auth_modal}), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def verify_two_factor_auth_code(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        user: User = User.objects.filter(username=request.session['username']).first()
        totp = pyotp.TOTP(user.two_fa_secret)
        if not totp.verify(request.POST['two_fa_code']):
            raise ValidationError(translation.gettext('logs_error_tfa_invalid_code'))
        user.two_fa = True
        user.save()
        return http_resp(content=json.dumps(obj={'status': translation.gettext('logs_success_tfa_enabled')}), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def two_factor_auth_verify_login(request: req) -> http_resp:
    is_logged_in(request)
    try:
        user: User = User.objects.filter(username=request.session['username']).first()
        totp = pyotp.TOTP(user.two_fa_secret)
        if not totp.verify(request.POST['two_fa_code']):
            raise translation.gettext('logs_error_tfa_invalid_code')
        del request.session['two_fa_required']
        return http_resp(content=json.dumps(obj={'status': translation.gettext('logs_success_tfa_verified')}), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def disable_two_factor_auth(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        user: User = User.objects.filter(username=request.session['username']).first()
        if not user.two_fa:
            raise translation.gettext('logs_error_tfa_already_disabled')
        user.two_fa_secret = None
        user.two_fa = False
        user.save()
        return http_resp(content=json.dumps(obj={'status': translation.gettext('logs_success_tfa_disabled')}), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def delete_account(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        user: User = User.objects.filter(username=request.POST['username']).first()
        if not user:
            raise ValidationError(translation.gettext('logs_error_user_not_found %(username)s') % {'username': request.POST['username']})
        if request.POST['username'] != request.session['username']:
            raise ValidationError(translation.gettext('logs_error_user_cannot_delete_other'))
        if not check_password(request.POST['password'], user.password):
            raise ValidationError(translation.gettext('logs_error_password_wrong %(username)s') % {'username': request.POST['username']})
        del request.session['username']
        del request.session['session_token']
        user.delete()
        activate_lang(request)
        json_data = {'title': 'Transcendence',
                     'status': translation.gettext('logs_success_user_deleted %(username)s') % {'username': user.username}}
        return http_resp(content=json.dumps(obj=json_data), status=200)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def add_friend(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        if request.session['username'] == request.POST['friend_user']:
            raise ValidationError(translation.gettext('logs_error_friend_cannot_be_with_self'))
        friend: User = User.objects.filter(username=request.POST['friend_user']).first()
        if not friend:
            raise ValidationError(translation.gettext('logs_error_user_not_found %(username)s') % {'username': request.POST['friend_user']})
        user: User = User.objects.filter(username=request.session['username']).first()
        find_friend = Friend.objects.filter(user_id=user.id,
                                            friend_id=friend)
        if find_friend:
            raise ValidationError(translation.gettext('logs_error_friend_already %(username)s') % {'username': request.POST['friend_user']})
        Friend.objects.create(user_id=user.id,
                              friend=friend)
        return http_resp(content=json.dumps(obj={'status': translation.gettext('logs_success_friend_added')}), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def remove_friend(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        user: User = User.objects.filter(username=request.session['username']).first()
        friend = Friend.objects.filter(user_id=user).filter(friend__username=request.POST['friend_user']).first()
        if not friend:
            raise ValidationError(translation.gettext('logs_error_user_not_found %(username)s') % {'username': request.POST['friend_user']})
        friend.delete()
        return http_resp(content=json.dumps(obj={'status': translation.gettext('logs_success_friend_removed')}), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def change_language(request: req) -> http_resp:
    if is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_out"))), status=401)
    try:
        request.session['lang'] = request.POST['lang']
        activate_lang(request)
        return http_resp(content=json.dumps(obj={'status': translation.gettext('logs_success_language_updated')}), status=200)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)
