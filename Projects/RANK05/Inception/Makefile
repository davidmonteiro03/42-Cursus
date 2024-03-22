# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 14:10:59 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/22 11:06:38 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

APP_PATH = /home/$(USER)/app

all: prepare
	@docker compose -f ./srcs/docker-compose.yml up -d --build

prepare:
	@mkdir -p $(APP_PATH)
	@mkdir -p $(APP_PATH)/wordpress
	@mkdir -p $(APP_PATH)/mariadb

down:
	@docker compose -f ./srcs/docker-compose.yml down

re:
	@docker compose -f ./srcs/docker-compose.yml up -d --build

clean: down
	@docker system prune -af

fclean: clean
	@if [ -n "$$(docker ps -qa)" ]; then docker stop $$(docker ps -qa); fi
	@if [ -n "$$(docker ps -qa)" ]; then docker rm -f $$(docker ps -qa); fi
	@if [ -n "$$(docker images -q)" ]; then docker rmi -f $$(docker images -q); fi
	@if [ -n "$$(docker volume ls -q)" ]; then docker volume rm $$(docker volume ls -q); fi
	@if [ -n "$$(docker network ls --format '{{.Name}}' | grep -vE 'bridge|host|none')" ]; then docker network rm $$(docker network ls --format '{{.Name}}' | grep -vE 'bridge|host|none'); fi
	@docker system prune -af
	@sudo rm -rf $(APP_PATH)

.PHONY: all down re clean fclean
