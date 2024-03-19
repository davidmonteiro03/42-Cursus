# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 11:03:18 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/19 11:56:02 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:bullseye

RUN apt-get update -y
RUN apt-get upgrade -y

RUN apt-get install -y nginx openssl

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/dcaetano.crt \
	-keyout /etc/nginx/ssl/dcaetano.key \
	-subj "/C=PT/ST=Porto/L=Gaia/O=42 School/OU=dcaetano/CN=dcaetano/"

COPY ./conf/nginx.conf /etc/nginx/conf.d/

RUN mv /var/www/html/index.nginx-debian.html /var/www/html/index.html

RUN mkdir -p /run/nginx

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
