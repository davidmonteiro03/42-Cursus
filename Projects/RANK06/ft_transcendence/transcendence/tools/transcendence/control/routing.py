from django.urls import path
from .consumers import ControlConsumer

websocket_urlpatterns = [
    path('ws/', ControlConsumer.as_asgi()),
]
