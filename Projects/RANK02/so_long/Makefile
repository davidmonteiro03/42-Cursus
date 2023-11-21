# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 07:31:26 by dcaetano          #+#    #+#              #
#    Updated: 2023/11/21 13:10:40 by dcaetano         ###   ########.fr        #
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
MINILIBX_DIR	= minilibx-linux
MINILIBX_NAME	= libmlx.a
MINILIBX_FLAGS	= -g -lmlx -lXext -lX11 -lm -lz -lbsd

SRCS			= main.c \
					srcs/errors.c \
					srcs/free.c \
					srcs/init.c \
					srcs/parse_arg.c \
					srcs/parse_utils.c \
					srcs/utils.c \
					srcs/game/dir_init.c \
					srcs/game/img_init.c \
					srcs/game/prepare_game.c \
					srcs/game/init_game.c \
					srcs/game/play_game.c \
					srcs/game/moves.c \
					srcs/game/exit_game.c

SRCS_BONUS		= main_bonus.c \
					srcs/errors.c \
					srcs/free.c \
					srcs/init.c \
					srcs/parse_arg.c \
					srcs/parse_utils.c \
					srcs/utils.c \
					srcs/game/bonus/dir_init_bonus.c \
					srcs/game/bonus/img_init_bonus.c \
					srcs/game/bonus/prepare_game_bonus.c \
					srcs/game/bonus/init_game_bonus.c \
					srcs/game/bonus/play_game_bonus.c \
					srcs/game/bonus/moves_bonus.c \
					srcs/game/bonus/display_bonus.c \
					srcs/game/bonus/close_game_bonus.c \
					srcs/game/bonus/exit_game_bonus.c \
					srcs/game/bonus/fire_utils_bonus.c \
					srcs/game/bonus/display_utils_bonus.c

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_BONUS		= $(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))

EXEC			= so_long
EXEC_BONUS		= so_long_bonus

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
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(MINILIBX_DIR) > /dev/null 2>&1
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ -L$(LIBFT_DIR) -lft -L./$(MINILIBX_DIR) $(MINILIBX_FLAGS)
	@echo "$(CYAN)$(EXEC) $(GREEN)created$(RESET)!"

$(EXEC_BONUS): $(OBJS_BONUS)
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(MINILIBX_DIR) > /dev/null 2>&1
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ -L$(LIBFT_DIR) -lft -L./$(MINILIBX_DIR) $(MINILIBX_FLAGS)
	@echo "$(CYAN)$(EXEC_BONUS) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@make -s -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@make -s -C $(MINILIBX_DIR) clean > /dev/null 2>&1
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(EXEC) $(EXEC_BONUS)
	@make -s -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@echo "$(CYAN)$(EXEC) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(EXEC_BONUS) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
