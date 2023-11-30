# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 07:31:26 by dcaetano          #+#    #+#              #
#    Updated: 2023/11/30 20:04:35 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				= \033[1;91m
GREEN			= \033[1;92m
YELLOW			= \033[1;93m
CYAN			= \033[1;96m
RESET			= \033[1;0m

CC				= cc
CFLAGS			= -Wall -Wextra -Werror #-fsanitize=thread
THREADFLAGS		= -pthread
RM				= rm -rf

OBJS_DIR		= obj/
INCLUDES_DIR	= include/

SRCS			= main.c \
					src/actions.c \
					src/check.c \
					src/data_utils.c \
					src/execute.c \
					src/philo_utils.c \
					src/utils.c

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

EXEC			= philo

all: $(EXEC)

$(OBJS_DIR)%.o: ./%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $(THREADFLAGS) -c $< -o $@

$(OBJS_DIR)%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $(THREADFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $(THREADFLAGS) $^ -o $@
	@echo "$(CYAN)$(EXEC) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(EXEC)
	@echo "$(CYAN)$(EXEC) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
