# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 08:34:00 by dcaetano          #+#    #+#              #
#    Updated: 2023/10/17 17:44:18 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW			= \033[1;33m
GREEN			= \033[1;32m
CYAN			= \033[1;36m
MIN_TAB			= 25
MAX_TAB			= 35

SRCS_DIR		= .
INCLUDES_DIR	= .
LIBFT_DIR		= .
OBJS_DIR		= objs

SRCS			= $(wildcard $(SRCS_DIR)/*.c)
OBJS			= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

LIBFT			= libft.a
NAME_LIBFT		= Libft

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

all: $(LIBFT)

$(LIBFT): $(OBJS)
	@printf "$(YELLOW)Compiling %-$(MIN_TAB)s$(CYAN)" "$(NAME_LIBFT)"
	@ar rcs $@ $^
	@printf "$(GREEN)%-$(MIN_TAB)s => compiled!$(CYAN)\n" "$(NAME_LIBFT)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@printf "$(YELLOW)Compiling %-$(MIN_TAB)s$(CYAN)" "$<"
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@
	@printf "$(GREEN)%-$(MIN_TAB)s => compiled!\n$(CYAN)" "$<"

clean:
	@printf "$(YELLOW)%-$(MAX_TAB)s$(CYAN)" "Removing objects from $(NAME_LIBFT)"
	@rm -rf $(OBJS_DIR)
	@printf "$(GREEN)%-$(MIN_TAB)s => removed!\n$(CYAN)" "Objects from $(NAME_LIBFT)"

fclean: clean
	@printf "$(YELLOW)%-$(MAX_TAB)s$(CYAN)" "Removing $(NAME_LIBFT)"
	@rm -f $(LIBFT)
	@printf "$(GREEN)%-$(MIN_TAB)s => removed!\n$(CYAN)" "$(NAME_LIBFT)"

re: fclean all

.PHONY: all clean fclean re
