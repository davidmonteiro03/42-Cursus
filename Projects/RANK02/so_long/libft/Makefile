# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 22:33:33 by dcaetano          #+#    #+#              #
#    Updated: 2024/04/30 08:22:32 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -rf
RANLIB = ranlib

NAME = libft.a

SRCS = ft_atoi.c ft_isalpha.c ft_itoa.c ft_lstdelone.c ft_lstnew.c ft_memcpy.c \
	ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_bzero.c \
	ft_isascii.c ft_lstadd_back.c ft_lstiter.c ft_lstsize.c ft_memmove.c \
	ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_calloc.c \
	ft_isdigit.c ft_lstadd_front.c ft_lstlast.c ft_memchr.c ft_memset.c ft_putstr_fd.c \
	ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_isalnum.c ft_isprint.c \
	ft_lstclear.c ft_lstmap.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c \
	ft_strmapi.c ft_strtrim.c \
	ft_format.c ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putnbr.c ft_putptr.c \
	ft_putstr.c \
	get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
INCS = ./

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
