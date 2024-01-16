# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 07:31:26 by dcaetano          #+#    #+#              #
#    Updated: 2024/01/16 13:11:39 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				= \033[1;91m
GREEN			= \033[1;92m
YELLOW			= \033[1;93m
CYAN			= \033[1;96m
RESET			= \033[1;0m

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g #-fsanitize=address
RM				= rm -rf

OBJS_DIR		= obj/
INCLUDES_DIR	= include/

LIBFT_DIR		= libft
LIBFT_NAME		= libft.a
MINILIBX_DIR	= minilibx-linux
MINILIBX_NAME	= libmlx.a
MINILIBX_FLAGS	= -g -lmlx -lXext -lX11 -lm -lz -lbsd

SRCS			= main.c \
					src/errors.c \
					src/exit.c \
					src/free.c \
					src/init.c \
					src/init2.c \
					src/init3.c \
					src/game/draw_utils.c \
					src/game/game_utils.c \
					src/game/get_info.c \
					src/game/hook_handler.c \
					src/game/img_utils.c \
					src/game/init_game.c \
					src/game/minimap_check_1.c \
					src/game/minimap_check_2.c \
					src/game/minimap_check_3.c \
					src/game/minimap_utils.c \
					src/game/play_game.c \
					src/game/raycast_utils.c \
					src/game/raycast.c \
					src/parser/config/parse_args.c \
					src/parser/config/parse_colors.c \
					src/parser/config/parse_config.c \
					src/parser/config/parse_dups.c \
					src/parser/config/parse_textures.c \
					src/parser/config/parse_type.c \
					src/parser/map/parse_border_utils.c \
					src/parser/map/parse_border_utils2.c \
					src/parser/map/parse_border_utils3.c \
					src/parser/map/parse_border_utils4.c \
					src/parser/map/parse_border_utils5.c \
					src/parser/map/parse_border_utils6.c \
					src/parser/map/parse_border_utils7.c \
					src/parser/map/parse_border.c \
					src/parser/map/parse_dups.c \
					src/parser/map/parse_map.c \
					src/parser/map/parse_player.c \
					src/parser/parse_file.c \
					src/parser/parse_info.c \
					src/parser/parse_input.c \
					src/setup/set_config.c \
					src/setup/set_map.c \
					src/utils/buildfree.c \
					src/utils/display_file.c \
					src/utils/get_lines.c \
					src/utils/get_size.c \
					src/utils/free.c \
					src/utils/strcmp.c \
					src/utils/utils1.c

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

EXEC			= cub3D

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
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(MINILIBX_DIR) > /dev/null 2>&1
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ -L$(LIBFT_DIR) -lft -L./$(MINILIBX_DIR) $(MINILIBX_FLAGS)
	@echo "$(CYAN)$(EXEC) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@make -s -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@make -s -C $(MINILIBX_DIR) clean > /dev/null 2>&1
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(EXEC)
	@make -s -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@echo "$(CYAN)$(EXEC) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
