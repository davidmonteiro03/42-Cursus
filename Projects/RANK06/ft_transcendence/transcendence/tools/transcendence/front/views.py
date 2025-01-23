from django.shortcuts import render
from django.views.decorators.http import require_GET as req_get
from django.views.decorators.http import require_POST as req_post
from django.http import HttpRequest as req
from django.http import HttpResponse as http_resp
from django.conf import settings
from pathlib import Path
from control.utils import get_session, load_template

root: Path = settings.BASE_DIR / 'front'
templates_path: Path = root / 'templates'
pages_path: Path = templates_path / 'pages'

# Create your views here.
@req_get
def main(request: req) -> http_resp:
    template_name: str = str(templates_path / 'main.html')
    return render(request=request,
                  context=get_session(request=request),
                  template_name=template_name,
                  status=200)

@req_post
def navbar(request: req) -> http_resp:
    template_name: str = str(templates_path / 'navbar.html')
    return load_template(request=request, template_name=template_name)

@req_post
def modal(request: req) -> http_resp:
    template_name: str = str(templates_path / 'modal.html')
    return load_template(request=request, template_name=template_name)

@req_post
def footer(request: req) -> http_resp:
    template_name: str = str(templates_path / 'footer.html')
    return load_template(request=request, template_name=template_name)

@req_post
def content(request: req, page: str) -> http_resp:
    template_name: str = str(pages_path / f'{page}.html')
    return load_template(request=request, template_name=template_name)

