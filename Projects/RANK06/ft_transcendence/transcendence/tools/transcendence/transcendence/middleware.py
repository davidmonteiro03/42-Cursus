import http, os
from django.http import HttpResponseServerError, HttpResponse, HttpRequest
from django.template import loader
from django.conf import settings
from django.shortcuts import redirect

class CustomErrorHandlerMiddleware:
    def __init__(self, get_response: HttpResponse):
        self.get_response = get_response

    def __call__(self, request: HttpRequest):
        try:
            response: HttpResponse = self.get_response(request)
            full_path = f"https://{os.environ.get('HOSTNAME')}:{os.environ.get('DJANGO_PORT')}{request.path}"
            if request.method == 'POST' or full_path == os.environ.get('REDIRECT_URI') or \
                (response.status_code >= 200 and response.status_code < 400):
                return response
            html = loader.render_to_string(settings.BASE_DIR / 'error.html',
                                           context={'code': response.status_code,
                                                    'message': http.HTTPStatus(response.status_code).phrase})
            # return HttpResponse(html, status=response.status_code)
            return redirect('/')
        except Exception as e:
            return HttpResponseServerError('Error occurred')
