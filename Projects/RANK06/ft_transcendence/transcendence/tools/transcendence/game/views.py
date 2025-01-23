from pathlib import Path
from django.conf import settings
from django.views.decorators.http import require_POST as req_post
from django.http import HttpRequest as req
from django.http import HttpResponse as http_resp
from control.utils import is_logged_in, error_to_dict, load_template, matchmaking, get_session
import json
from control.models import User
from django.utils import translation
from django.core.exceptions import ValidationError
from control.validators import UsernameValidator
from PIL import Image
import datetime
from .models import Match, Tournament
from django.template import loader
from django.db.models import Q

root: Path = settings.BASE_DIR / 'game'
templates_path: Path = root / 'templates'
pages_path: Path = templates_path / 'pages'

min_points: int = 3
max_points: int = 20

# Create your views here.
@req_post
def content(request: req, page: str) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    user = User.objects.filter(username=request.session['username']).first()
    if not user:
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext('logs_error_user_not_found %(username)s') % {'username': request.POST['username']})), status=401)
    if user.null_password:
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_config_pass"))), status=401)
    template_name: str = str(pages_path / f'{page}.html')
    return load_template(request=request, template_name=template_name)

@req_post
def p_vs_p_config_user(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    username_validator: UsernameValidator = UsernameValidator()
    try:
        username_validator(request.POST['opponent_alias'])
        if request.POST['opponent_alias'] == request.session['username']:
            raise ValidationError(translation.gettext("logs_error_game_same_alias_1"))
        home_player = {'alias_name': request.session['username']}
        away_player = {'alias_name': request.POST['opponent_alias']}
        json_data = {'home_player': home_player, 'away_player': away_player}
        return http_resp(content=json.dumps(obj=json_data), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def p_vs_ai_config_user(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        home_player = {'alias_name': request.session['username']}
        away_player = {'alias_name': 'AI'}
        json_data = {'home_player': home_player, 'away_player': away_player}
        return http_resp(content=json.dumps(obj=json_data), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def p_vs_p_config_game(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        field = {}
        if request.FILES and request.FILES['field_image']:
            try:
                Image.open(request.FILES['field_image']).verify()
                field = {'map': request.FILES['field_image'].name}
            except:
                raise ValidationError(translation.gettext("logs_error_image_invalid_upload"))
        else:
            field = {'color': request.POST['field_color']}
        json_data = {'ball': {'color': request.POST['ball_color']},
                     'field': field,
                     'max_points': int(request.POST['max_points']),
                     'left_padel': {'color': request.POST['left_padel_color']},
                     'right_padel': {'color': request.POST['right_padel_color']},
                     'winner': translation.gettext("main_game_winner")}
        if json_data['max_points'] < min_points or json_data['max_points'] > max_points:
            raise ValidationError(translation.gettext("logs_error_game_range_points %(min_points)s %(max_points)s") % {'min_points': min_points, 'max_points': max_points})
        return http_resp(content=json.dumps(obj=json_data), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def p_vs_ai_config_game(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        field = {}
        if request.FILES and request.FILES['field_image']:
            try:
                Image.open(request.FILES['field_image']).verify()
                field = {'map': request.FILES['field_image'].name}
            except:
                raise ValidationError(translation.gettext("logs_error_image_invalid_upload"))
        else:
            field = {'color': request.POST['field_color']}
        json_data = {'ball': {'color': request.POST['ball_color']},
                     'field': field,
                     'max_points': int(request.POST['max_points']),
                     'left_padel': {'color': request.POST['left_padel_color']},
                     'right_padel': {'color': request.POST['right_padel_color']},
                     'winner': translation.gettext("main_game_winner")}
        if json_data['max_points'] < min_points or json_data['max_points'] > max_points:
            raise ValidationError(translation.gettext("logs_error_game_range_points %(min_points)s %(max_points)s") % {'min_points': min_points, 'max_points': max_points})
        return http_resp(content=json.dumps(obj=json_data), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def tournament_config(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        field = {}
        if request.FILES and request.FILES['field_image']:
            try:
                Image.open(request.FILES['field_image']).verify()
                field = {'map': request.FILES['field_image'].name}
            except:
                raise ValidationError(translation.gettext("logs_error_image_invalid_upload"))
        else:
            field = {'color': request.POST['field_color']}
        json_data = {'ball': {'color': request.POST['ball_color']},
                     'field': field,
                     'max_points': int(request.POST['max_points']),
                     'host': {'alias_name': request.session['username'], 'padel_color': request.POST['host_padel_color']},
                     'next_game': translation.gettext("main_game_next"),
                     'matches': translation.gettext("main_game_matches"),
                     'winner': translation.gettext("main_game_winner"),
                     'players_auto_next_round': translation.gettext("main_game_players_auto_next_round")}
        if json_data['max_points'] < min_points or json_data['max_points'] > max_points:
            raise ValidationError(translation.gettext("logs_error_game_range_points %(min_points)s %(max_points)s") % {'min_points': min_points, 'max_points': max_points})
        return http_resp(content=json.dumps(obj=json_data), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def tournament_check_player(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    username_validator: UsernameValidator = UsernameValidator()
    try:
        username_validator(request.POST['player_alias'])
        if request.POST['player_alias'] == request.session['username']:
            raise ValidationError(translation.gettext("logs_error_game_same_alias_2"))
        host_player = {'alias_name': request.POST['player_alias'],
                       'padel_color': request.POST['padel_color'],
                       'status': translation.gettext("logs_game_tour_checked %(alias_name)s") % {'alias_name': request.POST['player_alias']}}
        return http_resp(content=json.dumps(obj=host_player), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def match_making(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        json_data: dict = json.loads(request.body)
        players_data: dict = json_data['players']
        list_data: list = list(players_data.values())
        round_data: int = int(json_data['rounds'])
        matches_data: list = matchmaking(list_data, round_data)
        return http_resp(content=json.dumps(obj=matches_data), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def save_game(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        json_data: dict = json.loads(request.body)
        user: User = User.objects.filter(username=request.session['username']).first()
        Match.objects.create(user_id=user.id,
                             timestamp=json_data['timestamp'],
                             home_player_alias_name=json_data['home_player_alias_name'],
                             home_player_score=json_data['home_player_score'],
                             away_player_alias_name=json_data['away_player_alias_name'],
                             away_player_score=json_data['away_player_score'])
        return http_resp(content=json.dumps(obj={'status': translation.gettext('logs_success_game_saved')}), status=201)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def save_tournament(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        json_data: dict = json.loads(request.body)
        user: User = User.objects.filter(username=request.session['username']).first()
        tournament: Tournament = Tournament.objects.create(user_id=user.id,
                                                           timestamp=json_data['timestamp'],
                                                           winner=json_data['winner'])
        done_games: list[dict] = json_data['done_games']
        for game in done_games:
            Match.objects.create(user_id=user.id,
                                 tournament_id=tournament.id,
                                 timestamp=game['timestamp'],
                                 home_player_alias_name=game['home_player_alias_name'],
                                 home_player_score=game['home_player_score'],
                                 away_player_alias_name=game['away_player_alias_name'],
                                 away_player_score=game['away_player_score'],
                                 round_count=game['round'],
                                 round_type=game['type'])
        return http_resp(content=json.dumps(obj={'status': translation.gettext('logs_success_tournament_saved')}), status=201)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

@req_post
def check_data(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        json_data: dict = json.loads(request.body)
        game_data: dict = {}
        if json_data['currentPage'] == "index/" or \
           json_data['currentPage'] == "p-vs-p-config-user/" or \
           json_data['currentPage'] == "tour-config/":
            game_data['history'] = json_data['history']
            game_data['currentPage'] = json_data['currentPage']
        elif json_data['currentPage'] == "p-vs-p-config-game/" or json_data['currentPage'] == "p-vs-ai-config-game/":
            game_data['history'] = json_data['history']
            game_data['currentPage'] = json_data['currentPage']
            game_data['players'] = json_data['players']
        elif json_data['currentPage'] == "tour-check-players/":
            game_data['history'] = json_data['history']
            game_data['currentPage'] = json_data['currentPage']
            try:
                game_data['tour'] = {}
                game_data['tour']['config'] = json_data['tour']['config']
                game_data['tour']['config']['next_game'] = translation.gettext("main_game_next")
                game_data['tour']['config']['matches'] = translation.gettext("main_game_matches")
                game_data['tour']['config']['winner'] = translation.gettext("main_game_winner")
                game_data['tour']['config']['players_auto_next_round'] = translation.gettext("main_game_players_auto_next_round")
                game_data['tour']['host'] = json_data['tour']['host']
                game_data['tour']['players'] = {}
                game_data['tour']['players'][request.session['username']] = json_data['tour']['host']
            except:
                try:
                    game_data['tour'] = {}
                    game_data['tour']['config'] = {}
                    game_data['tour']['config']['ball'] = json_data['config']['ball']
                    game_data['tour']['config']['field'] = json_data['config']['field']
                    game_data['tour']['config']['max_points'] = json_data['config']['max_points']
                    game_data['tour']['config']['next_game'] = translation.gettext("main_game_next")
                    game_data['tour']['config']['matches'] = translation.gettext("main_game_matches")
                    game_data['tour']['config']['winner'] = translation.gettext("main_game_winner")
                    game_data['tour']['config']['players_auto_next_round'] = translation.gettext("main_game_players_auto_next_round")
                    game_data['tour']['players'] = {}
                    game_data['tour']['players'][request.session['username']] = {}
                    game_data['tour']['players'][request.session['username']]['alias_name'] = json_data['players']['home_player']['alias_name']
                    game_data['tour']['players'][request.session['username']]['padel_color'] = json_data['config']['left_padel']['color']
                    game_data['tour']['host'] = game_data['tour']['players'][request.session['username']]
                except:
                    pass
        else:
            game_data = json_data
        return http_resp(content=json.dumps(obj=game_data), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)

def get_stats_tour(request: req, tour_id: int) -> dict:
    user: User = User.objects.filter(username=request.session['username']).first()
    tournament: Tournament = Tournament.objects.filter(Q(user_id=user.id) & Q(id=tour_id)).first()
    matches = Match.objects.filter(Q(user_id=user.id) & Q(tournament_id=tournament.id))
    context: dict = get_session(request)
    context['tour_data'] = {}
    tour_date = datetime.datetime.fromtimestamp(tournament.timestamp / 1000)
    context['tour_data']['day'] = f"{tour_date.day:02d}"
    context['tour_data']['month'] = f"{tour_date.month:02d}"
    context['tour_data']['hours'] = f"{tour_date.hour:02d}"
    context['tour_data']['minutes'] = f"{tour_date.minute:02d}"
    context['tour_data']['seconds'] = f"{tour_date.second:02d}"
    context['tour_data']['winner'] = tournament.winner
    context['tour_data']['rounds'] = []
    helpful_dict: dict = {}
    for m in matches:
        if m.round_type == "main_game_tour_play_off":
            round_type = f"{m.round_type}_{m.round_count}"
            round_description = translation.gettext("main_game_tour_play_off %(round_count)s") % {'round_count': m.round_count}
        else:
            round_type = m.round_type
            round_description = m.round_type
            round_description = translation.gettext(m.round_type)
        helpful_dict[round_type] = {}
        helpful_dict[round_type]['description'] = round_description
        helpful_dict[round_type]['matches'] = []
    for m in matches:
        if m.round_type == "main_game_tour_play_off":
            round_type = f"{m.round_type}_{m.round_count}"
        else:
            round_type = m.round_type
        date = datetime.datetime.fromtimestamp(m.timestamp / 1000)
        match_data: dict = {}
        match_data['day'] = f"{date.day:02d}"
        match_data['month'] = f"{date.month:02d}"
        match_data['hours'] = f"{date.hour:02d}"
        match_data['minutes'] = f"{date.minute:02d}"
        match_data['seconds'] = f"{date.second:02d}"
        match_data['score_home'] = m.home_player_score
        match_data['score_away'] = m.away_player_score
        match_data['alias_home'] = m.home_player_alias_name
        match_data['alias_away'] = m.away_player_alias_name
        helpful_dict[round_type]['matches'].append(match_data)
    for t in helpful_dict.values():
        context['tour_data']['rounds'].append(t)
    return context

def load_template_tour(template_name: str, request: req, tour_id: int) -> http_resp:
    try:
        html = loader.render_to_string(request=request,
                                       context=get_stats_tour(request=request, tour_id=tour_id),
                                       template_name=template_name)
        return http_resp(content=json.dumps({'html': html}), status=200)
    except loader.TemplateDoesNotExist:
        return http_resp(content=json.dumps({'error': translation.gettext('logs_error_template_not_found %(template_name)s') % {'template_name': template_name}}), status=404)
    except Exception:
        return http_resp(content=json.dumps({'error': translation.gettext('logs_error_template_could_not_load %(template_name)s') % {'template_name': template_name}}), status=400)

@req_post
def content_tour_stats(request: req, id: int) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    user = User.objects.filter(username=request.session['username']).first()
    if not user:
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext('logs_error_user_not_found %(username)s') % {'username': request.POST['username']})), status=401)
    if user.null_password:
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_config_pass"))), status=401)
    template_name: str = str(pages_path / 'tour-stats.html')
    return load_template_tour(request=request, template_name=template_name, tour_id=id)

@req_post
def get_stats(request: req) -> http_resp:
    if not is_logged_in(request):
        return http_resp(content=json.dumps(obj=error_to_dict(e=translation.gettext("logs_error_need_sign_in_up"))), status=401)
    try:
        user: User = User.objects.filter(username=request.session['username']).first()
        if not user:
            raise ValidationError(translation.gettext('logs_error_user_not_found %(username)s') % {'username': request.POST['username']})

        json_data: dict = {}

        json_data['game'] = {}
        json_data['tournament'] = {}
        json_data['point'] = {}

        json_data['game']['data_labels'] = [translation.gettext("main_game_wins"),
                                    translation.gettext("main_game_losses")]
        json_data['tournament']['data_labels'] = [translation.gettext("main_game_wins"),
                                                  translation.gettext("main_game_losses")]
        json_data['point']['data_labels'] = [translation.gettext("main_game_scored_points"),
                                             translation.gettext("main_game_conceded_points")]

        json_data['game']['title'] = translation.gettext("main_game_stats")
        json_data['tournament']['title'] = translation.gettext("main_tour_stats")
        json_data['point']['title'] = translation.gettext("main_point_stats")

        matches = Match.objects.filter(Q(user_id=user.id) & (Q(home_player_alias_name=user.username) | Q(away_player_alias_name=user.username)))
        json_data['game']['data_datasets_data'] = [0, 0]
        for m in matches:
            if m.home_player_alias_name == user.username:
                json_data['game']['data_datasets_data'][0] += m.home_player_score > m.away_player_score
                json_data['game']['data_datasets_data'][1] += m.home_player_score < m.away_player_score
            else:
                json_data['game']['data_datasets_data'][0] += m.home_player_score < m.away_player_score
                json_data['game']['data_datasets_data'][1] += m.home_player_score > m.away_player_score

        tournaments = Tournament.objects.filter(user_id=user.id)
        json_data['tournament']['data_datasets_data'] = [0, 0]
        for t in tournaments:
            json_data['tournament']['data_datasets_data'][0] += t.winner == user.username
            json_data['tournament']['data_datasets_data'][1] += t.winner != user.username

        matches = Match.objects.filter(Q(user_id=user.id) & (Q(home_player_alias_name=user.username) | Q(away_player_alias_name=user.username)))
        json_data['point']['data_datasets_data'] = [0, 0]
        for m in matches:
            if m.home_player_alias_name == user.username:
                json_data['point']['data_datasets_data'][0] += m.home_player_score
                json_data['point']['data_datasets_data'][1] += m.away_player_score
            else:
                json_data['point']['data_datasets_data'][0] += m.away_player_score
                json_data['point']['data_datasets_data'][1] += m.home_player_score

        return http_resp(content=json.dumps(obj=json_data), status=200)
    except ValidationError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=401)
    except KeyError as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=422)
    except Exception as e:
        return http_resp(content=json.dumps(obj=error_to_dict(e=e)), status=400)
