from django.conf import settings

def languages(request):
    return {'LANGUAGES': settings.LANGUAGES, 'LANGUAGE_CODE': settings.LANGUAGE_CODE}
