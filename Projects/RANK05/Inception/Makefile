# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 17:42:36 by dcaetano          #+#    #+#              #
#    Updated: 2024/09/13 16:07:16 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

APP_PATH = $(HOME)/data

all: prepare
	@docker compose -f ./srcs/docker-compose.yml up --build

prepare:
	@mkdir -p $(APP_PATH)/wordpress
	@mkdir -p $(APP_PATH)/mariadb

build:
	@docker compose -f ./srcs/docker-compose.yml build

up:
	@docker compose -f ./srcs/docker-compose.yml up

down:
	@docker compose -f ./srcs/docker-compose.yml down

restart:
	@docker compose -f ./srcs/docker-compose.yml restart

stats:
	@docker compose -f ./srcs/docker-compose.yml stats

clean: down
	@docker compose -f ./srcs/docker-compose.yml down -v

fclean: clean
	@docker system prune -af
	@rm -rf $(APP_PATH)

system:
	@docker system df -v

rerun: down up

re: fclean all

.PHONY: all build up down restart stats clean fclean system rerun re
