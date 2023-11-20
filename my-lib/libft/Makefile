# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 14:06:11 by dcaetano          #+#    #+#              #
#    Updated: 2023/11/20 15:37:42 by dcaetano         ###   ########.fr        #
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

INCLUDES	= $(NAME).h get_next_line.h
OBJS_DIR	= obj/

NAME		= libft.a
SRCS		= ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_converthex.c \
				ft_format.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_printf.c \
				ft_putchar_fd.c \
				ft_putchar.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putnbr.c \
				ft_putnbru.c \
				ft_putptr.c \
				ft_putstr_fd.c \
				ft_putstr.c \
				ft_putstrhex.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_utoa.c \
				get_next_line.c \
				get_next_line_utils.c

OBJS		= $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $^
	@$(LIB) $(NAME)
	@echo "$(CYAN)$(NAME) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)$(NAME) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
