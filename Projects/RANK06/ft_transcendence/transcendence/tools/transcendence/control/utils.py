from urllib.parse import urlencode
from django.http import HttpRequest as req
from django.http import HttpResponse as http_resp
from .models import User, Friend
from game.models import Match, Tournament
from django.forms.models import model_to_dict
from django.template import loader
import json
from control.consumers import connections
from django.contrib.sessions.models import Session
from django.utils import translation
from random import randint
from django.db.models import Q
from django.conf import settings
import datetime

def activate_lang(request: req) -> None:
    try:
        translation.activate(request.session['lang'])
    except:
        translation.activate(settings.LANGUAGE_CODE)

def error_to_dict(e: str | list[str]) -> dict:
    if type(e) is str and len(e) >= 1:
        return {'0': e}
    try:
        listed: list = list(e)
        return {f'{i}': listed[i] for i in range(len(listed))}
    except Exception:
        return {'error': translation.gettext('logs_error_unknown')}

def build_url(protocol: str = None,
              domain: str = None,
              subdomain: str = None,
              port: int = None,
              route: str = None,
              query_params: dict = None) -> str:
    if not protocol:
        return None
    url: str = f"{protocol}://"
    if subdomain is not None:
        url += f"{subdomain}."
    if not domain:
        return None
    url += domain
    if port is not None:
        url += f":{port}"
    if route is not None:
        url += f"/{route}/"
    if query_params is not None:
        url += f"?{urlencode(query=query_params)}"
    return url

def get_friends(user: User) -> list:
    django_sessions = Session.objects.all()
    friends = []
    search_friends = Friend.objects.filter(user_id=user.id)
    for f in search_friends:
        friend_json = model_to_dict(instance=f.friend,
                                    exclude=['password'])
        if f.friend.anonymous_name:
            del friend_json['first_name']
            del friend_json['last_name']
        step_one = False
        for ds in django_sessions:
            ds_decoded = ds.get_decoded()
            if ds_decoded.get('username') and ds_decoded.get('username') == friend_json['username']:
                if not ds_decoded.get('two_fa_required'):
                    step_one = True
                    break
        step_two = False
        for c in connections:
            c_scope_session = c.scope.get('session')
            if not c_scope_session.get('username') or not c_scope_session.get('session_token'):
                continue
            if c_scope_session.get('username') == user.username:
                continue
            if c_scope_session.get('username') == friend_json['username']:
                step_two = True
                break
        friend_json['active'] = step_one and step_two
        friends.append(friend_json)
    return friends

def get_matches(user: User) -> list:
    matches = Match.objects.filter(Q(user_id=user.id) & (Q(home_player_alias_name=user.username) | Q(away_player_alias_name=user.username)))
    tmp_home_str: str = translation.gettext('main_game_home')
    tmp_away_str: str = translation.gettext('main_game_away')
    match_list: list = []
    for m in matches:
        date = datetime.datetime.fromtimestamp(m.timestamp / 1000)
        match_data: dict = {}
        match_data['day'] = f"{date.day:02d}"
        match_data['month'] = f"{date.month:02d}"
        match_data['hours'] = f"{date.hour:02d}"
        match_data['minutes'] = f"{date.minute:02d}"
        match_data['seconds'] = f"{date.second:02d}"
        match_data['tournament_id'] = m.tournament_id
        if m.home_player_alias_name == user.username:
            match_data['opponent'] = m.away_player_alias_name
            match_data['place'] = tmp_home_str
            match_data['win'] = m.home_player_score > m.away_player_score
        else:
            match_data['opponent'] = m.home_player_alias_name
            match_data['place'] = tmp_away_str
            match_data['win'] = m.home_player_score < m.away_player_score
        match_data['score_home'] = m.home_player_score
        match_data['score_away'] = m.away_player_score
        match_list.append(match_data)
    return match_list

def get_session(request: req) -> dict:
    context = {}
    try:
        user: User = User.objects.filter(username=request.session['username']).first()
        user_data: dict = model_to_dict(instance=user,
                                        exclude=['password'])
        translation.activate(user.lang)
        if request.session.get('session_token') and not request.session.get('two_fa_required'):
            context['control_user'] = user_data
            context['control_user']['friends'] = get_friends(user)
            context['control_user']['matches'] = get_matches(user)
    except Exception:
        activate_lang(request)
    return context

def is_logged_in(request: req) -> bool:
    if not request.session.get('session_token') or not request.session.get('username'):
        activate_lang(request)
        return False
    try:
        user: User = User.objects.filter(username=request.session['username']).first()
        if not user:
            return False
        translation.activate(user.lang)
        return True
    except:
        return False

def load_template(template_name: str, request: req) -> http_resp:
    try:
        html = loader.render_to_string(request=request,
                                       context=get_session(request=request),
                                       template_name=template_name)
        return http_resp(content=json.dumps({'html': html}), status=200)
    except loader.TemplateDoesNotExist:
        return http_resp(content=json.dumps({'error': translation.gettext('logs_error_template_not_found %(template_name)s') % {'template_name': template_name}}), status=404)
    except Exception:
        return http_resp(content=json.dumps({'error': translation.gettext('logs_error_template_could_not_load %(template_name)s') % {'template_name': template_name}}), status=400)

def find_next_power_of_two(n: int) -> int:
    if n and not (n & (n - 1)):
        return n
    while n & (n - 1):
        n &= n - 1
    return n << 1

def matchmaking(players: list[dict], round: int) -> list | None:
    if len(players) < 2:
        return None
    if len(players) <= 2:
        round_data = {'id': "main_game_tour_final", 'event': translation.gettext("main_game_tour_final")}
    elif len(players) <= 4:
        round_data = {'id': "main_game_tour_semi_finals", 'event': translation.gettext("main_game_tour_semi_finals")}
    elif len(players) <= 8:
        round_data = {'id': "main_game_tour_quarter_finals", 'event': translation.gettext("main_game_tour_quarter_finals")}
    elif len(players) <= 16:
        round_data = {'id': "main_game_tour_round_of_16", 'event': translation.gettext("main_game_tour_round_of_16")}
    else:
        round_data = {'id': "main_game_tour_play_off", 'event': translation.gettext("main_game_tour_play_off %(round_count)s") % {'round_count': round}}
    if len(players) % 2 == 0:
        games = [tuple[dict, dict] for _ in range(len(players) // 2)]
        for i in range(len(games)):
            pos_home: int = randint(0, len(players) - 1)
            p_home: dict = players.pop(pos_home)
            pos_away: int = randint(0, len(players) - 1)
            p_away: dict = players.pop(pos_away)
            games[i] = (p_home, p_away)
        return {'games': games, 'round': round_data}
    next_power_of_two: int = find_next_power_of_two(len(players))
    n_byes: int = next_power_of_two - len(players)
    games: list = [tuple[dict, dict] for _ in range((len(players) - n_byes) // 2)]
    byes: dict = {}
    for i in range(n_byes):
        pos_bye: int = randint(0, len(players) - 1)
        p_bye: dict = players.pop(pos_bye)
        byes[p_bye['alias_name']] = p_bye
    for i in range(n_byes, next_power_of_two // 2):
        pos_home: int = randint(0, len(players) - 1)
        p_home: dict = players.pop(pos_home)
        pos_away: int = randint(0, len(players) - 1)
        p_away: dict = players.pop(pos_away)
        games[i - n_byes] = (p_home, p_away)
    return {'games': games, 'byes': byes, 'round': round_data}
