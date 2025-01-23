from django.db import models
from control.models import User

# Create your models here.
class Tournament(models.Model):
    id = models.AutoField(verbose_name='ID',
                          primary_key=True,
                          unique=True,
                          blank=False,
                          null=False)
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    timestamp = models.BigIntegerField(verbose_name='timestamp',
                                       blank=False,
                                       null=False)
    winner = models.CharField(verbose_name='winner',
                              max_length=256,
                              blank=False,
                              null=False)

class Match(models.Model):
    id = models.AutoField(verbose_name='ID',
                          primary_key=True,
                          unique=True,
                          blank=False,
                          null=False)
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    tournament = models.ForeignKey(Tournament, on_delete=models.CASCADE, null=True)
    timestamp = models.BigIntegerField(verbose_name='timestamp',
                                       blank=False,
                                       null=False)
    home_player_alias_name = models.CharField(verbose_name='home player alias name',
                                              max_length=256,
                                              blank=False,
                                              null=False)
    home_player_score = models.IntegerField(verbose_name='home player score',
                                            blank=False,
                                            null=False)
    away_player_alias_name = models.CharField(verbose_name='away player alias name',
                                              max_length=256,
                                              blank=False,
                                              null=False)
    away_player_score = models.IntegerField(verbose_name='away player score',
                                            blank=False,
                                            null=False)
    round_count = models.IntegerField(verbose_name='round count',
                                      blank=False,
                                      null=True)
    round_type = models.CharField(verbose_name='round type',
                                  max_length=256,
                                  blank=False,
                                  null=True)
