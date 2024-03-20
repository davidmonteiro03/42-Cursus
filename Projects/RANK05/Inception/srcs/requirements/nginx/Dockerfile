FROM debian:bullseye

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y nginx openssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048\
	-keyout /etc/ssl/private/nginx-selfsigned.key\
	-out /etc/ssl/certs/nginx-selfsigned.crt\
	-subj "/C=PT/ST=Porto/L=Porto/O=42 School/OU=42 School/CN=David/UID=dcaetano"

COPY ./conf/nginx.conf /etc/nginx/conf.d/default.conf

RUN mkdir -p /run/nginx

CMD ["nginx", "-g", "daemon off;"]
