from django import forms
from .models import Match, Tournament

class MatchAdminForm(forms.ModelForm):
    class Meta:
        model = Match
        fields = '__all__'

class TournamentAdminForm(forms.ModelForm):
    class Meta:
        model = Tournament
        fields = '__all__'
