# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 07:31:26 by dcaetano          #+#    #+#              #
#    Updated: 2023/11/15 18:32:23 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				= \033[1;91m
GREEN			= \033[1;92m
YELLOW			= \033[1;93m
CYAN			= \033[1;96m
RESET			= \033[1;0m

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
RLFLAGS			= -lreadline
RM				= rm -rf

OBJS_DIR		= obj/
INCLUDES_DIR	= includes/

LIBFT_DIR		= libft
LIBFT_NAME		= libft.a

SRCS_HISTORY		= history.c
OBJS_HISTORY		= $(addprefix $(OBJS_DIR), $(SRCS_HISTORY:.c=.o))
EXEC_HISTORY		= history

SRCS_RL				= readline.c
OBJS_RL				= $(addprefix $(OBJS_DIR), $(SRCS_RL:.c=.o))
EXEC_RL				= readline

SRCS_SIGNALS		= signals.c
OBJS_SIGNALS		= $(addprefix $(OBJS_DIR), $(SRCS_SIGNALS:.c=.o))
EXEC_SIGNALS		= signals

SRCS_COMMANDS		= commands.c
OBJS_COMMANDS		= $(addprefix $(OBJS_DIR), $(SRCS_COMMANDS:.c=.o))
EXEC_COMMANDS		= commands

all:

$(OBJS_DIR)%.o: ./%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(EXEC_HISTORY): $(OBJS_HISTORY)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ $(RLFLAGS) \
		$(LIBFT_DIR)/$(LIBFT_DIR).a
	@echo "$(CYAN)$(EXEC_HISTORY) $(GREEN)created$(RESET)!"

$(EXEC_RL): $(OBJS_RL)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ $(RLFLAGS) \
		$(LIBFT_DIR)/$(LIBFT_DIR).a
	@echo "$(CYAN)$(EXEC_RL) $(GREEN)created$(RESET)!"

$(EXEC_SIGNALS): $(OBJS_SIGNALS)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ $(RLFLAGS) \
		$(LIBFT_DIR)/$(LIBFT_DIR).a
	@echo "$(CYAN)$(EXEC_SIGNALS) $(GREEN)created$(RESET)!"

$(EXEC_COMMANDS): $(OBJS_COMMANDS)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $^ -o $@ $(RLFLAGS) \
		$(LIBFT_DIR)/$(LIBFT_DIR).a
	@echo "$(CYAN)$(EXEC_COMMANDS) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean > /dev/null
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(EXEC_HISTORY) $(EXEC_RL) $(EXEC_SIGNALS) $(EXEC_COMMANDS)
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@echo "$(CYAN)$(EXEC_HISTORY) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(EXEC_RL) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(EXEC_SIGNALS) $(RED)removed$(RESET)!"
	@echo "$(CYAN)$(EXEC_COMMANDS) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
