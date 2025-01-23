from django.db import models
from django.core.exceptions import ValidationError
from django.contrib.auth.password_validation import validate_password
from .validators import NameValidator, UsernameValidator
from django.conf import settings

def password_validator(value):
    try:
        validate_password(value)
    except ValidationError as e:
        raise ValidationError(e)

# Create your models here.
class User(models.Model):
    id = models.AutoField(verbose_name='ID',
                          primary_key=True,
                          unique=True,
                          blank=False,
                          null=False)
    first_name = models.CharField(verbose_name='first name',
                                  max_length=256,
                                  validators=[NameValidator("first name")],
                                  blank=False,
                                  null=False)
    last_name = models.CharField(verbose_name='last name',
                                 max_length=256,
                                 validators=[NameValidator("last name")],
                                 blank=False,
                                 null=False)
    username = models.CharField(verbose_name='username',
                                max_length=256,
                                validators=[UsernameValidator()],
                                unique=True,
                                blank=False,
                                null=False)
    password = models.CharField(verbose_name='password',
                                max_length=256,
                                validators=[password_validator],
                                blank=False,
                                null=False)
    profile_image = models.ImageField(verbose_name='profile image',
                                blank=True,
                                null=True)
    ft_image = models.URLField(verbose_name='ft image',
                               max_length=4096)
    anonymous_name = models.BooleanField(verbose_name='anonymous name',
                                         default=False,
                                         blank=False,
                                         null=False)
    ft_link = models.BooleanField(verbose_name='oauth login',
                                  default=False,
                                  blank=False,
                                  null=False)
    two_fa = models.BooleanField(verbose_name='two factor authentication',
                                 default=False,
                                 blank=False,
                                 null=False)
    two_fa_secret = models.CharField(verbose_name='two factor authentication secret',
                                     max_length=256,
                                     blank=True,
                                     null=True)
    null_password = models.BooleanField(verbose_name='null password',
                                        default=True,
                                        blank=False,
                                        null=False)
    lang = models.CharField(verbose_name='language',
                            max_length=2,
                            default=settings.LANGUAGE_CODE,
                            blank=False,
                            null=False)

class Friend(models.Model):
    id = models.AutoField(verbose_name='ID',
                          primary_key=True,
                          unique=True,
                          blank=False,
                          null=False)
    user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='user_guy')
    friend = models.ForeignKey(User, on_delete=models.CASCADE, related_name='friend_guy')
