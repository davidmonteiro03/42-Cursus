# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 17:50:20 by dcaetano          #+#    #+#              #
#    Updated: 2024/02/10 23:45:38 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				= \033[1;91m
GREEN			= \033[1;92m
YELLOW			= \033[1;93m
CYAN			= \033[1;96m
RESET			= \033[1;0m

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

OBJS_DIR		= obj/
INCLUDES_DIR	= ./

SRCS			= mn_test.c

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

EXEC_MAIN		= mn_test

all: $(EXEC_MAIN)

$(OBJS_DIR)%.o: ./%.c
	@make -C ../../ft_printf
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(EXEC_MAIN): $(OBJS)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ ../libftprintf.a
	@echo "$(CYAN)$(EXEC_MAIN) $(GREEN)created$(RESET)!"

clean:
	@make -s -C ../../ft_printf clean > /dev/null 2>&1
	@$(RM) $(OBJS_DIR)
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@make -s -C ../../ft_printf fclean > /dev/null 2>&1
	@$(RM) $(EXEC_MAIN)
	@echo "$(CYAN)$(EXEC_MAIN) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re

