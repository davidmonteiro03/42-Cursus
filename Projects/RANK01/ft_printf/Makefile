# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 17:09:49 by dcaetano          #+#    #+#              #
#    Updated: 2024/02/06 17:49:26 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[1;91m
GREEN		= \033[1;92m
YELLOW		= \033[1;93m
CYAN		= \033[1;96m
RESET		= \033[1;0m

SRCS		= ft_printf.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a
AR			= ar rcs
LIB			= ranlib
RM			= rm -rf
CC			= cc
FLAGS		= -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."

$(NAME):$(OBJS)
	@make -s -C libft bonus > /dev/null 2>&1
	@cp libft/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@$(LIB) $(NAME)
	@echo "$(CYAN)$(NAME) $(GREEN)created$(RESET)!"

clean:
	@make -s -C libft clean > /dev/null 2>&1
	@$(RM) $(OBJS)
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@make -s -C libft fclean > /dev/null 2>&1
	@$(RM) $(NAME)
	@echo "$(CYAN)$(NAME) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
