# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 14:06:11 by dcaetano          #+#    #+#              #
#    Updated: 2023/11/21 17:21:57 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
CYAN		= \033[1;36m
RESET		= \033[1;0m
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
AR			= ar rcs
LIB			= ranlib

INCLUDES	= my_lib.h
OBJS_DIR	= obj/

EXEC		= test

NAME		= my_lib.a
SRCS		= buildfree.c \
				free.c

OBJS		= $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(EXEC): $(NAME)
	@$(CC) $(CFLAGS) -o $@ $^ main.c $(NAME) -lreadline libft.a
	@echo "$(YELLOW)Compiling $(CYAN)$(EXEC)$(RESET)..."
	@echo "$(CYAN)$(EXEC) $(GREEN)created$(RESET)!"

$(OBJS_DIR)%.o: %.c
	@make -s -C libft
	@cp libft/libft.a .
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $^
	@$(LIB) $(NAME)
	@echo "$(CYAN)$(NAME) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@make -s clean -C libft > /dev/null
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(NAME)
	@make -s fclean -C libft > /dev/null
	@echo "$(CYAN)$(NAME) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
