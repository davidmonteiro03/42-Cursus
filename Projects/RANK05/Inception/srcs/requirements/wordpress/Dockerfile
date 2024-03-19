# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 11:03:18 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/19 16:28:46 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:bullseye

RUN apt-get update -y
RUN apt-get upgrade -y

RUN apt-get install -y wget php php-fpm php-mysql

RUN adduser --system nginx
RUN addgroup --system nginx
COPY ./conf/php-fpm.conf /etc/php7.4/php-fpm.conf
COPY ./conf/www.conf /etc/php7.4/php-fpm.d/www.conf

WORKDIR /var/www/html/

COPY ./tools/wp-config.sh /tmp/wp-config.sh
ENTRYPOINT ["sh", "/tmp/wp-config.sh"]
