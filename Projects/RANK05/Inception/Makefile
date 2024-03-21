# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 14:10:59 by dcaetano          #+#    #+#              #
#    Updated: 2024/03/21 17:54:53 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@docker compose -f ./srcs/docker-compose.yml up -d --build

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
	@docker system prune -af --volumes
	@docker volume prune -f
	@docker network prune -f

.PHONY: all down re clean fclean
