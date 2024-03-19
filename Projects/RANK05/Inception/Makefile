# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 14:57:57 by shovsepy          #+#    #+#              #
#    Updated: 2024/03/19 12:23:45 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: build up

build:
	@sudo docker compose -f ./srcs/docker-compose.yml build

up:
	@sudo docker compose -f ./srcs/docker-compose.yml up -d

down:
	@sudo docker compose -f ./srcs/docker-compose.yml down

start:
	@sudo docker compose -f ./srcs/docker-compose.yml start

stop:
	@sudo docker compose -f ./srcs/docker-compose.yml stop

logs:
	@sudo docker compose -f ./srcs/docker-compose.yml logs

status:
	@sudo docker ps

delete: down
	@sudo rm -rf srcs/data
	@sudo docker system prune -f

rmi:
	@sudo docker rmi nginx
	@echo

re: delete all

.PHONY: all build up down start stop logs status prune rmi re
