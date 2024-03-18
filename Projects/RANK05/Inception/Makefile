# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 16:42:15 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/18 17:59:47 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: up

up:
	@sudo docker compose -f ./srcs/docker-compose.yml up -d

down:
	@sudo docker compose -f ./srcs/docker-compose.yml down

start:
	@sudo docker compose -f ./srcs/docker-compose.yml start

stop:
	@sudo docker compose -f ./srcs/docker-compose.yml stop

status:
	@sudo docker ps

delete:
	@sudo docker stop $$(sudo docker ps -qa)
	@sudo docker rm $$(sudo docker ps -qa)
	@sudo docker rmi -f $$(sudo docker images -qa)

re: delete all

.PHONY: all up down start stop re
