#!/bin/bash
# Django
cd /transcendence
python -m venv env
source env/bin/activate
pip install --upgrade pip
pip install --upgrade --no-cache-dir -r requirements.txt
python manage.py makemigrations control game
python manage.py migrate
python manage.py createsuperuser --no-input
django-admin compilemessages -l en -l pt -l es
python manage.py collectstatic --no-input
uvicorn transcendence.asgi:application --host 0.0.0.0 --port $DJANGO_PORT
