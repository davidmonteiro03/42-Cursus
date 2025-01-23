from django.core.exceptions import ValidationError
from django.contrib.auth import password_validation
from django.utils.deconstruct import deconstructible
import regex, string
from django.utils import translation

min_name_length: int = 3
min_user_length: int = 3
max_user_length: int = 10
min_pass_length: int = 8

@deconstructible
class NameValidator:
    def __init__(self, description: str):
        self.description: str = description
    def __call__(self, value: str):
        if len(value) < min_name_length:
            raise ValidationError(message=translation.gettext('logs_error_name_1 %(description)s %(min_name_length)s') % {'description': self.description,
                                                                                                                          'min_name_length': min_name_length})
        if not regex.match(r'\p{L}*$', string=value, flags=regex.UNICODE):
            raise ValidationError(message=translation.gettext('logs_error_name_2 %(description)s') % {'description': self.description})
        if not regex.match(r'\p{Lu}\p{Ll}*$', string=value, flags=regex.UNICODE):
            raise ValidationError(message=translation.gettext('logs_error_name_3 %(description)s') % {'description': self.description})

@deconstructible
class UsernameValidator:
    def __call__(self, value: str):
        if len(value) < min_user_length or len(value) > max_user_length:
            raise ValidationError(message=translation.gettext('logs_error_username_1 %(min_user_length)s %(max_user_length)s') % {'min_user_length': min_user_length,
                                                                                                                                  'max_user_length': max_user_length})
        if not regex.match(r'[a-z0-9\-\_]*$', string=value):
            raise ValidationError(message=translation.gettext('logs_error_username_2'))
        if not regex.match(r'^[a-z]', string=value):
            raise ValidationError(message=translation.gettext('logs_error_username_3'))

class PasswordValidator:
    def validate(self, password: str, user=None):
        if len(password) < min_pass_length:
            raise ValidationError(message=translation.gettext('logs_error_password_1 %(min_pass_length)s') % {'min_pass_length': min_pass_length})
        if not any(char.islower() for char in password):
            raise ValidationError(message=translation.gettext('logs_error_password_2'))
        if not any(char.isupper() for char in password):
            raise ValidationError(message=translation.gettext('logs_error_password_3'))
        if not any(char.isdigit() for char in password):
            raise ValidationError(message=translation.gettext('logs_error_password_4'))
        if not regex.search(f"[{regex.escape(string.punctuation)}]", password):
            raise ValidationError(message=translation.gettext('logs_error_password_5'))
    def get_help_text(self):
        return translation.gettext('logs_error_password_requirements_1')

class CommonPasswordValidator(password_validation.CommonPasswordValidator):
    def validate(self, password: str, user=None):
        if password.lower().strip() in self.passwords:
            raise ValidationError(message=translation.gettext('logs_error_password_6'))
    def get_help_text(self):
        return translation.gettext('logs_error_password_requirements_2')
