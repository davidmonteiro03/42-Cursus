from . import views
from django.urls import path

urlpatterns = [
    path(route='', view=views.main, name='main'),
    path(route='navbar/', view=views.navbar, name='navbar'),
    path(route='content/<str:page>/', view=views.content, name='content'),
    path(route='modal/', view=views.modal, name='modal'),
    path(route='footer/', view=views.footer, name='footer'),
]

