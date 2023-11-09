# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 07:31:26 by dcaetano          #+#    #+#              #
#    Updated: 2023/10/26 18:15:28 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				= \033[1;31m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
CYAN			= \033[1;36m
RESET			= \033[1;0m

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

OBJS_DIR		= obj/
INCLUDES_DIR	= includes/

SRCS			= main.c srcs/calculate.c \
					srcs/errors.c \
					srcs/operations.c \
					srcs/prepareargs.c \
					srcs/preparenums.c \
					srcs/push_swap.c \
					srcs/sort.c \
					srcs/sort_utils.c \
					srcs/stack_utils.c \
					srcs/utils.c

SRCS_BONUS		= checker.c srcs/calculate.c \
					srcs/errors.c \
					srcs/operations.c \
					srcs/prepareargs.c \
					srcs/preparenums.c \
					srcs/push_swap.c \
					srcs/sort.c \
					srcs/sort_utils.c \
					srcs/stack_utils.c \
					srcs/utils.c
LIBFT_DIR		= libft
LIBFT_NAME		= libft.a

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_BONUS		= $(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))

EXEC			= push_swap
EXEC_BONUS		= checker

all: $(EXEC)

bonus: $(EXEC_BONUS)

$(OBJS_DIR)%.o: ./%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(OBJS_DIR)%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(EXEC): $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ -L$(LIBFT_DIR) -lft
	@echo "$(CYAN)$(EXEC) $(GREEN)created$(RESET)!"

$(EXEC_BONUS): $(OBJS_BONUS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ -L$(LIBFT_DIR) -lft
	@echo "$(CYAN)$(EXEC_BONUS) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(EXEC) $(EXEC_BONUS)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(CYAN)$(EXEC) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(EXEC_BONUS) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
