# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 07:31:26 by dcaetano          #+#    #+#              #
#    Updated: 2023/11/22 15:24:01 by dcaetano         ###   ########.fr        #
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
INCLUDES_DIR	= includes/

LIBFT_DIR		= libft
LIBFT_NAME		= libft.a

EXEC			= test

SRCS			= main.c \
					srcs/buildfree.c \
					srcs/free.c \
					srcs/ft_mnstrlen.c \
					srcs/ft_strbuild.c \

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all:

$(OBJS_DIR)%.o: ./%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(OBJS_DIR)%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(EXEC): $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ $(LIBFT_DIR)/$(LIBFT_NAME) \
		-lreadline
	@echo "$(CYAN)$(EXEC) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@make -s -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(EXEC)
	@make -s -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@echo "$(CYAN)$(LIBFT_NAME) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(EXEC) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
