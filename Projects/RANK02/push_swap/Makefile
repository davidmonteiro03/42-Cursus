# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:51:40 by dcaetano          #+#    #+#              #
#    Updated: 2024/04/29 07:11:16 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG = #-g -fsanitize=address

PSLIB = push_swap.a
PSSRCS = ./srcs/ft_free.c ./srcs/ft_parse.c ./srcs/ft_error.c \
	./srcs/ft_fill.c ./srcs/ft_display.c ./srcs/ft_checkdups.c \
	./srcs/ft_compare.c ./srcs/ft_operations.c ./srcs/ft_sortlist.c \
	./srcs/ft_utils.c ./srcs/ft_execute.c ./srcs/ft_sort_utils.c \
	./srcs/ft_sort_utils2.c ./srcs/ft_sort_utils3.c
PSOBJS = $(PSSRCS:.c=.o)

CHLIB = checker.a
CHSRCS = ./srcs/ft_parse_bonus.c ./srcs/ft_checker_bonus.c \
	./srcs/ft_checker_utils.c
CHOBJS = $(CHSRCS:.c=.o)

NAME = push_swap
SRCS = main.c
OBJS = $(SRCS:.c=.o)
INCS = ./includes/

BONUS = checker
SRCS_B = bonus.c
OBJS_B = $(SRCS_B:.c=.o)
INCS_B = ./includes/

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS) $(PSLIB)
	$(CC) $(CFLAGS) $(DEBUG)-I$(INCS) $(OBJS) $(PSLIB) -o $(NAME)

$(BONUS): $(OBJS_B) $(CHLIB)
	$(CC) $(CFLAGS) $(DEBUG)-I$(INCS_B) $(OBJS_B) $(CHLIB) -o $(BONUS)

$(PSOBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CHOBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_B): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PSLIB): $(PSOBJS)
	make -C libft bonus
	cp libft/libft.a $(PSLIB)
	ar rcs $(PSLIB) $(PSOBJS)
	ranlib $(PSLIB)

$(CHLIB): $(CHOBJS) $(PSOBJS)
	make -C libft bonus
	cp libft/libft.a $(CHLIB)
	ar rcs $(CHLIB) $(PSOBJS) $(CHOBJS)
	ranlib $(CHLIB)

clean:
	make -C libft clean
	rm -rf $(PSOBJS) $(CHOBJS) $(OBJS) $(OBJS_B)

fclean: clean
	make -C libft fclean
	rm -rf $(PSLIB) $(CHLIB) $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
