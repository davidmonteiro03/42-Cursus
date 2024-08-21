# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 08:07:07 by dcaetano          #+#    #+#              #
#    Updated: 2024/05/08 10:10:03 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Commands

CC = cc
RM = rm -rf
AR = ar rcs
RANLIB = ranlib
CP = cp
WGET = wget
TAR = tar -xzf
MV = mv

# Flags

CFLAGS = -Wall -Wextra -Werror -O3 -g

# Minilibx

MLXLINK = https://cdn.intra.42.fr/document/document/25858/minilibx-linux.tgz
MLXZIP = minilibx-linux.tgz
MLXUNZIP = minilibx-linux
MLXFOLDER = mlx
MLXLIB = mlx/libmlx.a
MLXFLAGS = -lX11 -lXext -lm

# so_long library (not minilibx)

SLLIB = so_long.a
SLSRCS = ./srcs/mandatory/errors/so_long_error.c \
		./srcs/mandatory/parse/so_long_parse.c \
		./srcs/mandatory/parse/so_long_parse_content.c \
		./srcs/mandatory/parse/so_long_parse_path.c \
		./srcs/mandatory/exit/so_long_exit.c \
		./srcs/mandatory/free/so_long_free.c \
		./srcs/mandatory/free/so_long_free2.c \
		./srcs/mandatory/init/so_long_init.c \
		./srcs/mandatory/init/so_long_init2.c \
		./srcs/mandatory/display/so_long_display_file.c \
		./srcs/mandatory/display/so_long_display_map.c \
		./srcs/mandatory/utils/free.c \
		./srcs/mandatory/utils/readfile.c \
		./srcs/mandatory/utils/strcmp.c \
		./srcs/mandatory/utils/mapdup.c \
		./srcs/mandatory/utils/getvalues.c \
		./srcs/mandatory/utils/istransp.c \
		./srcs/mandatory/game/so_long_play.c \
		./srcs/mandatory/game/so_long_close.c \
		./srcs/mandatory/game/so_long_block.c \
		./srcs/mandatory/game/so_long_key_handler.c \
		./srcs/mandatory/game/so_long_find_nearest_collect.c \
		./srcs/mandatory/game/so_long_get_best_frame.c \
		./srcs/mandatory/game/show_map/so_long_show_map.c \
		./srcs/mandatory/game/show_map/so_long_show_map_case1.c \
		./srcs/mandatory/game/show_map/so_long_show_map_case2.c \
		./srcs/mandatory/game/show_map/so_long_show_map_case3.c
SLOBJS = $(SLSRCS:.c=.o)

SLLIB_B = so_long_bonus.a
SLSRCS_B = ./srcs/bonus/errors/so_long_error.c \
		./srcs/bonus/parse/so_long_parse.c \
		./srcs/bonus/parse/so_long_parse_content.c \
		./srcs/bonus/parse/so_long_parse_path.c \
		./srcs/bonus/exit/so_long_exit.c \
		./srcs/bonus/free/so_long_free.c \
		./srcs/bonus/free/so_long_free2.c \
		./srcs/bonus/init/so_long_init.c \
		./srcs/bonus/init/so_long_init2.c \
		./srcs/bonus/init/so_long_init3.c \
		./srcs/bonus/display/so_long_display_file.c \
		./srcs/bonus/display/so_long_display_map.c \
		./srcs/bonus/utils/free.c \
		./srcs/bonus/utils/readfile.c \
		./srcs/bonus/utils/strcmp.c \
		./srcs/bonus/utils/mapdup.c \
		./srcs/bonus/utils/getvalues.c \
		./srcs/bonus/utils/joinfree.c \
		./srcs/bonus/utils/enemies.c \
		./srcs/bonus/utils/generateposition.c \
		./srcs/bonus/utils/removenode.c \
		./srcs/bonus/utils/findnode.c \
		./srcs/bonus/utils/ptrinptrs.c \
		./srcs/bonus/utils/wrongfree.c \
		./srcs/bonus/utils/fireballs.c \
		./srcs/bonus/utils/istransp.c \
		./srcs/bonus/game/so_long_play.c \
		./srcs/bonus/game/so_long_close.c \
		./srcs/bonus/game/so_long_key_handler.c \
		./srcs/bonus/game/so_long_find_nearest_collect.c \
		./srcs/bonus/game/so_long_lose.c \
		./srcs/bonus/game/so_long_enemies.c \
		./srcs/bonus/game/so_long_enemies2.c \
		./srcs/bonus/game/so_long_hit_moving.c \
		./srcs/bonus/game/so_long_hit_static.c \
		./srcs/bonus/game/so_long_fix_map_sizes.c \
		./srcs/bonus/game/so_long_fireballs.c \
		./srcs/bonus/game/so_long_update.c \
		./srcs/bonus/game/so_long_block.c \
		./srcs/bonus/game/so_long_get_best_frame.c \
		./srcs/bonus/game/so_long_update_info.c \
		./srcs/bonus/game/show_map/so_long_show_map.c \
		./srcs/bonus/game/show_map/so_long_show_map_case1.c \
		./srcs/bonus/game/show_map/so_long_show_map_case2.c \
		./srcs/bonus/game/show_map/so_long_show_map_case3.c
SLOBJS_B = $(SLSRCS_B:.c=.o)

# so_long executable

INCS = ./includes

NAME = so_long
SRCS = main.c
OBJS = $(SRCS:.c=.o)

BONUS = so_long_bonus
SRCS_B = bonus.c
OBJS_B = $(SRCS_B:.c=.o)

# Compile

all: $(NAME)

bonus: $(BONUS)

# so_long library objs

$(SLOBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SLLIB): $(SLOBJS)
	$(MAKE) -C libft
	@if [ -d "$(MLXFOLDER)" ]; then \
		$(MAKE) -C $(MLXFOLDER); \
	fi
	$(CP) libft/libft.a $(SLLIB)
	$(AR) $(SLLIB) $(SLOBJS)
	$(RANLIB) $(SLLIB)

$(SLOBJS_B): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SLLIB_B): $(SLOBJS_B)
	$(MAKE) -C libft
	@if [ -d "$(MLXFOLDER)" ]; then \
		$(MAKE) -C $(MLXFOLDER); \
	fi
	$(CP) libft/libft.a $(SLLIB_B)
	$(AR) $(SLLIB_B) $(SLOBJS_B)
	$(RANLIB) $(SLLIB_B)

# so_long executable objs

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(SLLIB)
	$(CC) $(CFLAGS) -I$(INCS) $(OBJS) $(SLLIB) $(MLXLIB) $(MLXFLAGS) -o $(NAME)

$(OBJS_B): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS): $(OBJS_B) $(SLLIB_B)
	$(CC) $(CFLAGS) -I$(INCS) $(OBJS_B) $(SLLIB_B) $(MLXLIB) $(MLXFLAGS) -o $(BONUS)

# Minilibx

downloadmlx:
	@if [ ! -d "$(MLXFOLDER)" ]; then \
		$(WGET) $(MLXLINK); \
		$(TAR) $(MLXZIP) && $(RM) $(MLXZIP); \
		$(MV) $(MLXUNZIP) $(MLXFOLDER); \
	fi

# Delete

clean:
	$(MAKE) -C libft clean
	@if [ -f "$(MLXFOLDER)/Makefile.gen" ]; then \
		$(MAKE) -C $(MLXFOLDER) clean; \
	fi
	$(RM) $(SLOBJS) $(OBJS) $(SLOBJS_B) $(OBJS_B)

fclean: clean
	$(MAKE) -C libft fclean
	@if [ -d "$(MLXFOLDER)" ]; then \
		$(RM) $(MLXFOLDER); \
	fi
	$(RM) $(SLLIB) $(SLLIB_B) $(NAME) $(BONUS)

# Rebuild

re: fclean all

.PHONY: all bonus clean downloadmlx fclean re
