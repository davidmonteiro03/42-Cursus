# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 17:50:20 by dcaetano          #+#    #+#              #
#    Updated: 2024/04/12 11:58:25 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				= \033[1;91m
GREEN			= \033[1;92m
YELLOW			= \033[1;93m
CYAN			= \033[1;96m
RESET			= \033[1;0m

CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98 -O3
RM				= rm -rf

OBJS_DIR		= obj/
INCLUDES_DIR	= ./

SRCS			= PmergeMe.cpp main.cpp

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

EXEC			= PmergeMe

all: $(EXEC)

$(OBJS_DIR)%.o: ./%.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."
	@$(CXX) $(CXXFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(EXEC): $(OBJS)
	@$(CXX) $(CXXFLAGS) -I$(INCLUDES_DIR) $^ -o $@
	@echo "$(CYAN)$(EXEC) $(GREEN)created$(RESET)!"

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@$(RM) $(EXEC)
	@echo "$(CYAN)$(EXEC) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re

