FROM debian:bullseye

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y nginx openssl
RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/dcaetano.crt \
	-keyout /etc/nginx/ssl/dcaetano.key \
	-subj "/C=PT/ST=Porto/L=Gaia/O=42 School/OU=dcaetano/CN=dcaetano/"

COPY ./config/nginx.conf /etc/nginx/conf.d

RUN mkdir -p /run/nginx

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
