# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 07:31:26 by dcaetano          #+#    #+#              #
#    Updated: 2023/11/05 14:37:02 by dcaetano         ###   ########.fr        #
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

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

EXEC			= so_long

all: $(EXEC)

$(OBJS_DIR)%.o: ./%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(OBJS_DIR)%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(EXEC): $(OBJS)
	@make -C $(LIBFT_DIR) > /dev/null
	@make -C $(MINILIBX_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ -L$(LIBFT_DIR) -lft -L./$(MINILIBX_DIR) $(MINILIBX_FLAGS)
	@echo "$(CYAN)$(EXEC) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean > /dev/null
	@make -C $(MINILIBX_DIR)
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(EXEC)
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@echo "$(CYAN)$(EXEC) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
