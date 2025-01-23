from django.urls import path
from . import views
from front import views as front_views

urlpatterns = [
    path(route='navbar/', view=front_views.navbar, name='navbar'),
    path(route='content/tournament-<int:id>/', view=views.content_tour_stats, name='content-tour-stats'),
    path(route='content/<str:page>/', view=views.content, name='content'),
    path(route='modal/', view=front_views.modal, name='modal'),
    path(route='footer/', view=front_views.footer, name='footer'),
    path(route='p-vs-p-config-user/', view=views.p_vs_p_config_user, name='p-vs-p-config-user'),
    path(route='p-vs-p-config-game/', view=views.p_vs_p_config_game, name='p-vs-p-config-game'),
    path(route='p-vs-ai-config-user/', view=views.p_vs_ai_config_user, name='p-vs-ai-config-user'),
    path(route='p-vs-ai-config-game/', view=views.p_vs_ai_config_game, name='p-vs-ai-config-game'),
    path(route='tournament-config/', view=views.tournament_config, name='tournament-config'),
    path(route='tournament-check-player/', view=views.tournament_check_player, name='tournament-check-player'),
    path(route='match-making/', view=views.match_making, name='match-making'),
    path(route='save-game/', view=views.save_game, name='save-game'),
    path(route='save-tournament/', view=views.save_tournament, name='save-tournament'),
    path(route='check-data/', view=views.check_data, name='check-data'),
    path(route='get-stats/', view=views.get_stats, name='get-stats'),
]

