# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 10:17:28 by dcaetano          #+#    #+#              #
#    Updated: 2023/11/23 17:07:35 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[1;91m
GREEN		= \033[1;92m
YELLOW		= \033[1;93m
CYAN		= \033[1;96m
RESET		= \033[1;0m

NAME		= libftprintf.a
LIBFTNAME	= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFTDIR	= ./libft

SRCS		= ft_printf.c ft_format.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."

makelibft:
	@echo "$(CYAN)$(LIBFTNAME) $(GREEN)created$(RESET)!"

$(NAME):$(OBJS)
	@make -s -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)
	@ar -r $(NAME) $(OBJS)
	@echo "$(CYAN)$(NAME) $(GREEN)created$(RESET)!"

clean:
	@make -s -C $(LIBFTDIR) clean > /dev/null 2>&1
	@rm -rf $(OBJS)
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@make -s -C $(LIBFTDIR) fclean > /dev/null 2>&1
	@rm -rf $(NAME) $(LIBFTNAME)
	@echo "$(CYAN)$(LIBFTNAME) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(NAME) $(RED)removed$(RESET)!"

re: fclean all
