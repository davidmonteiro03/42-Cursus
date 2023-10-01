# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 14:19:47 by dcaetano          #+#    #+#              #
#    Updated: 2023/10/01 21:31:50 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= ft_create_elem.c ft_exec_create_elem.c

SRCS	= ${addprefix ./srcs/, ${SRC}}

OBJS	= ${SRCS:.c=.o}

INCLUDES	= ./includes/

NAME	= libft

AR	= ar rcs

RM	= rm -f

LIB	= ranlib

CC	= cc

FLAGS	= -Wall -Werror -Wextra

NAME_EXEC	= main

SRCS_EXEC	= main.c

all:	${NAME} ${NAME_EXEC}

.c.o:
	${CC} ${FLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

${NAME_EXEC}:${NAME}
	${CC} ${FLAGS} ${SRCS_EXEC} ${NAME} -o ${NAME_EXEC}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}
	${RM} ${NAME_EXEC}

re:	fclean all

.PHONY: clean fclean
