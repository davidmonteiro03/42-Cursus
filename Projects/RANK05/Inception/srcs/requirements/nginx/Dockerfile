FROM debian:bullseye

RUN apt-get update
RUN apt-get install -y nginx openssl

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/nginx.crt \
	-keyout /etc/nginx/ssl/nginx.key \
	-subj "/C=PT/ST=Porto/L=Porto/O=42 School/OU=dcaetano/CN=dcaetano/"

COPY ./nginx.conf /etc/nginx/conf.d

RUN mkdir -p /run/nginx

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
