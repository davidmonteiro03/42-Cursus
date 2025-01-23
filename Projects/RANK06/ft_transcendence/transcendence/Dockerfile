# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 11:59:35 by dcaetano          #+#    #+#              #
#    Updated: 2024/12/24 16:07:36 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM python:latest
RUN apt update && apt upgrade -y
RUN apt install -y python3-venv python3-psycopg2 gettext
RUN rm -rf /var/lib/apt/lists/*
COPY tools/transcendence /transcendence
COPY tools/entrypoint.sh /tmp/entrypoint.sh
RUN chmod +x /tmp/entrypoint.sh
ENTRYPOINT [ "bash", "/tmp/entrypoint.sh" ]
