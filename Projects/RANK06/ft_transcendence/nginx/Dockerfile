# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:38:43 by dcaetano          #+#    #+#              #
#    Updated: 2024/12/12 12:39:58 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM nginx:latest
RUN apt update && apt upgrade -y
RUN apt install -y openssl
RUN rm -rf /var/lib/apt/lists/*
COPY tools/entrypoint.sh /tmp/entrypoint.sh
RUN chmod +x /tmp/entrypoint.sh
ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
