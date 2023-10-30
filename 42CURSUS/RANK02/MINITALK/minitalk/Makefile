# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 07:31:26 by dcaetano          #+#    #+#              #
#    Updated: 2023/10/30 09:15:32 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED					= \033[1;31m
GREEN				= \033[1;32m
YELLOW				= \033[1;33m
CYAN				= \033[1;36m
RESET				= \033[1;0m

CC					= cc
CFLAGS				= -Wall -Wextra -Werror
RM					= rm -rf

OBJS_DIR			= obj/
INCLUDES_DIR		= includes/

SRCS_SERVER			= server.c
SRCS_CLIENT			= client.c

SRCS_SERVER_BONUS	= server_bonus.c
SRCS_CLIENT_BONUS	= client_bonus.c

LIBFT_DIR			= libft
LIBFT_NAME			= libft.a

OBJS_SERVER			= $(addprefix $(OBJS_DIR), $(SRCS_SERVER:.c=.o))
OBJS_CLIENT			= $(addprefix $(OBJS_DIR), $(SRCS_CLIENT:.c=.o))

OBJS_SERVER_BONUS	= $(addprefix $(OBJS_DIR), $(SRCS_SERVER_BONUS:.c=.o))
OBJS_CLIENT_BONUS	= $(addprefix $(OBJS_DIR), $(SRCS_CLIENT_BONUS:.c=.o))

EXEC_SERVER			= server
EXEC_CLIENT			= client

EXEC_SERVER_BONUS	= server_bonus
EXEC_CLIENT_BONUS	= client_bonus

all: $(EXEC_SERVER) $(EXEC_CLIENT)

bonus: $(EXEC_SERVER_BONUS) $(EXEC_CLIENT_BONUS)

$(OBJS_DIR)%.o: ./%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(EXEC_SERVER): $(OBJS_SERVER)
	@make -C $(LIBFT_DIR) >/dev/null
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ -L$(LIBFT_DIR) -lft
	@echo "$(CYAN)$(EXEC_SERVER) $(GREEN)created$(RESET)!"

$(EXEC_CLIENT): $(OBJS_CLIENT)
	@make -C $(LIBFT_DIR) >/dev/null
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ -L$(LIBFT_DIR) -lft
	@echo "$(CYAN)$(EXEC_CLIENT) $(GREEN)created$(RESET)!"

$(EXEC_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	@make -C $(LIBFT_DIR) >/dev/null
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ -L$(LIBFT_DIR) -lft
	@echo "$(CYAN)$(EXEC_SERVER_BONUS) $(GREEN)created$(RESET)!"

$(EXEC_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	@make -C $(LIBFT_DIR) >/dev/null
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ -L$(LIBFT_DIR) -lft
	@echo "$(CYAN)$(EXEC_CLIENT_BONUS) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean >/dev/null
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(EXEC_SERVER) $(EXEC_CLIENT) $(EXEC_SERVER_BONUS) $(EXEC_CLIENT_BONUS)
	@make -C $(LIBFT_DIR) fclean >/dev/null
	@echo "$(CYAN)$(EXEC_SERVER) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(EXEC_CLIENT) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(EXEC_SERVER_BONUS) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(EXEC_CLIENT_BONUS) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
