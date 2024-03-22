# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 18:50:59 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/22 15:19:39 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y mariadb-server

RUN mkdir -p /var/run/mysqld &&\
	chown -R mysql:mysql /var/run/mysqld &&\
	chown -R mysql:mysql /var/lib/mysql
RUN rm -f /etc/mysql/my.cnf
COPY ./tools/entrypoint.sh /tmp/entrypoint.sh
RUN chmod +x /tmp/entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]
