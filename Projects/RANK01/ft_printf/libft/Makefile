# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 13:06:53 by dcaetano          #+#    #+#              #
#    Updated: 2024/02/06 17:24:04 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= \033[1;91m
GREEN		= \033[1;92m
YELLOW		= \033[1;93m
CYAN		= \033[1;96m
RESET		= \033[1;0m

SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_split.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS		= ${SRCS:.c=.o}

SRCS_BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME		= libft.a

AR			= ar rcs

LIB			= ranlib

RM			= rm -rf

CC			= cc

FLAGS		= -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."

$(NAME):${OBJS}
	@${AR} ${NAME} ${OBJS}
	@${LIB} ${NAME}
	@echo "$(CYAN)$(NAME) $(GREEN)created$(RESET)!"

bonus:${OBJS} ${OBJS_BONUS}
	@${AR} ${NAME} ${OBJS} ${OBJS_BONUS}
	@${LIB} ${NAME}
	@echo "$(CYAN)$(NAME) $(GREEN)created$(RESET)!"

so:
	@${CC} -nostartfiles -fPIC ${FLAGS} ${SRCS} ${SRCS_BONUS}
	@gcc -nostartfiles -shared -o libft.so ${OBJS} ${OBJS_BONUS}

clean:
	@${RM} ${OBJS} ${OBJS_BONUS}
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean:	clean
	@${RM} ${NAME}
	@echo "$(CYAN)$(NAME) $(RED)removed$(RESET)!"

re:	fclean all

.PHONY: all bonus clean fclean re
