# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 07:31:26 by dcaetano          #+#    #+#              #
#    Updated: 2023/11/29 12:28:20 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				= \033[1;91m
GREEN			= \033[1;92m
YELLOW			= \033[1;93m
CYAN			= \033[1;96m
RESET			= \033[1;0m

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=address
RM				= rm -rf

OBJS_DIR		= obj/
INCLUDES_DIR	= includes/

LIBFT_DIR		= libft
LIBFT_NAME		= libft.a

EXEC			= test
EXEC_2			= test2
EXEC_3			= test3

SRCS			= main.c \
					srcs/buildfree.c \
					srcs/free.c \
					srcs/utils.c \
					srcs/wildcards/wildcard_1.c \
					srcs/wildcards/wildcard_2.c

SRCS_2			= main_2.c \
					srcs/buildfree.c \
					srcs/free.c

SRCS_3			= main_3.c \
					srcs/buildfree.c \
					srcs/exec_utils.c \
					srcs/free.c

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_2			= $(addprefix $(OBJS_DIR), $(SRCS_2:.c=.o))
OBJS_3			= $(addprefix $(OBJS_DIR), $(SRCS_3:.c=.o))

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

$(EXEC_2): $(OBJS_2)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ $(LIBFT_DIR)/$(LIBFT_NAME) \
		-lreadline
	@echo "$(CYAN)$(EXEC_2) $(GREEN)created$(RESET)!"

$(EXEC_3): $(OBJS_3)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ $(LIBFT_DIR)/$(LIBFT_NAME) \
		-lreadline
	@echo "$(CYAN)$(EXEC_3) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@make -s -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(EXEC) $(EXEC_2) $(EXEC_3)
	@make -s -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@echo "$(CYAN)$(LIBFT_NAME) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(EXEC) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(EXEC_2) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(EXEC_3) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
