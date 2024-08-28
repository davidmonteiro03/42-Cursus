# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 13:21:51 by dcaetano          #+#    #+#              #
#    Updated: 2024/08/28 16:03:56 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR            = ar rcs
RM            = rm -rf
SOURCES       = ft_format.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_base.c \
                ft_putptr.c ft_putstr.c
OBJECTS       = $(SOURCES:.c=.o)
SOURCES_BONUS = ft_format_bonus.c ft_printf_bonus.c ft_putchar.c ft_putnbr.c \
                ft_putnbr_base.c ft_putptr.c ft_putstr.c
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
NAME          = libftprintf.a
BONUS         = libftprintf_bonus.a
CFLAGS        = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

$(BONUS): $(OBJECTS_BONUS)
	$(AR) $(NAME) $(OBJECTS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
