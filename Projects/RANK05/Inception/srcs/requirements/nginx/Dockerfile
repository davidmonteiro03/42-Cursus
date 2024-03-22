# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 14:23:39 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/22 17:53:20 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y nginx openssl

COPY ./tools/entrypoint.sh /tmp/entrypoint.sh
RUN mkdir -p /tmp/html
COPY ./index/* /tmp/html/
RUN chmod 777 /tmp/html/*
RUN cp -r /tmp/html/* /var/www/html/
RUN chmod +x /tmp/entrypoint.sh

EXPOSE 443

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]
