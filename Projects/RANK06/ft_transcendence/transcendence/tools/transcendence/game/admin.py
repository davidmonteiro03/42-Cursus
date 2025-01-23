from django.contrib import admin
from .models import Match, Tournament
from .forms import MatchAdminForm, TournamentAdminForm

class MatchAdmin(admin.ModelAdmin):
    form = MatchAdminForm

class TournamentAdmin(admin.ModelAdmin):
    form = TournamentAdminForm

admin.site.register(Match, MatchAdmin)
admin.site.register(Tournament, TournamentAdmin)
