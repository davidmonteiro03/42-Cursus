# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 17:50:20 by dcaetano          #+#    #+#              #
#    Updated: 2023/12/08 12:57:34 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				= \033[1;91m
GREEN			= \033[1;92m
YELLOW			= \033[1;93m
CYAN			= \033[1;96m
RESET			= \033[1;0m

CC				= c++
CFLAGS			= -Wall -Wextra -Werror -std=c++98
RM				= rm -rf

OBJS_DIR		= obj/

SRCS			= main.cpp ClapTrap.cpp ScavTrap.cpp

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

EXEC			= scav_trap

all: $(EXEC)

$(OBJS_DIR)%.o: ./%.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(CYAN)$(EXEC) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(EXEC)
	@echo "$(CYAN)$(EXEC) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re

