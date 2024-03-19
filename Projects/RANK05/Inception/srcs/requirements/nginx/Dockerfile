# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 11:03:18 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/19 11:16:24 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# set the base image
FROM debian:bullseye

# update and upgrade the system
RUN apt-get update -y
RUN apt-get upgrade -y

# install nginx and openssl
RUN apt-get install -y nginx openssl

# create ssl certificate
RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/dcaetano.crt \
	-keyout /etc/nginx/ssl/dcaetano.key \
	-subj "/C=PT/ST=Porto/L=Porto/O=42 School/OU=dcaetano/CN=dcaetano/"

# copy the nginx configuration file
COPY ./conf/nginx.conf /etc/nginx/conf.d/

# create the directory for the pid file
RUN mkdir -p /run/nginx

# expose the ports
EXPOSE 443

# start the nginx server
CMD ["nginx", "-g", "daemon off;"]
