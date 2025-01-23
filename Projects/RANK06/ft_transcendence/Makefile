# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 17:42:36 by dcaetano          #+#    #+#              #
#    Updated: 2025/01/22 08:13:53 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@docker-compose up --build

build:
	@docker-compose build

up:
	@docker-compose up

down:
	@docker-compose down

restart:
	@docker-compose restart

stats:
	@docker-compose stats

clean: down
	@docker-compose down -v

fclean: clean
	@docker system prune -af

system:
	@docker system df -v

rerun: down up

re: fclean all

.PHONY: all build up down restart stats clean fclean system rerun re
