#!/bin/bash

env_file=.env # env file

# write a line to env file
writeenvfile () {
	if [ $# -ne 1 ]; then return; fi
	echo "$1" >> "$env_file"
}

# read text
readtext () {
	if [ $# -ne 1 ]; then return; fi
	read -r -p   "$1=" text             || { echo; writeenvfile "$1="; return; }
	writeenvfile "$1='$text'"
}

# read password
readpassword () {
	if [ $# -ne 1 ]; then return; fi
	read -rs -p  "$1=" password && echo || { echo; writeenvfile "$1="; return; }
	writeenvfile "$1='$password'"
}

> "$env_file" # create env file

# Debug
writeenvfile '# Debug'
writeenvfile "DEBUG=False"

# Host Information
writeenvfile '# Host Information'
writeenvfile "HOSTNAME='$(hostname | tr '[:upper:]' '[:lower:]')'"
writeenvfile "IP='$(hostname -I | awk '{ print $1 }')'"

# Django
writeenvfile '# Django'
writeenvfile "SECRET_KEY='$(tr -dc 'a-z0-9!@#$%^&*(-_=+)' < /dev/urandom | head -c50)'"
readtext     'DJANGO_PORT'
readtext     'DJANGO_SUPERUSER_USERNAME'
readtext     'DJANGO_SUPERUSER_EMAIL'
readpassword 'DJANGO_SUPERUSER_PASSWORD'
readtext     'CLIENT_ID'
readtext     'CLIENT_SECRET'
hostname="$(source .env && echo $HOSTNAME)"
port="$(source .env && echo $DJANGO_PORT)"
callback='control/callback'
writeenvfile "REDIRECT_URI='https://$hostname:$port/$callback'"

# PostgreSQL
writeenvfile '# PostgreSQL'
readtext     'POSTGRES_DB'
readpassword 'POSTGRES_PASSWORD'

# printf '%*s' "$(tput cols)" '' | tr ' ' '='; cat .env # show env file
