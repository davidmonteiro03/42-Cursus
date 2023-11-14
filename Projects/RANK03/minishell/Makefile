# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 08:42:34 by ade-pinh          #+#    #+#              #
#    Updated: 2023/11/14 08:20:24 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### ---------- TEXT FORMATTING AND COLORS ---------- ###

# Text Colors
Black					=\033[0;30m
Red						=\033[0;31m
Green					=\033[0;32m
Yellow					=\033[0;33m
Blue					=\033[0;34m
Magenta					=\033[0;35m
Cyan					=\033[0;36m
White					=\033[0;37m

# Bright Text Colors
Bright_Black			=\033[1;30m
Bright_Red				=\033[1;31m
Bright_Green			=\033[1;32m
Bright_Yellow			=\033[1;33m
Bright_Blue				=\033[1;34m
Bright_Magenta			=\033[1;35m
Bright_Cyan				=\033[1;36m
Bright_White			=\033[1;37m

# Background Colors
Background_Black		=\033[40m
Background_Red			=\033[41m
Background_Green		=\033[42m
Background_Yellow		=\033[43m
Background_Blue			=\033[44m
Background_Magenta		=\033[45m
Background_Cyan			=\033[46m
Background_White		=\033[47m

# Text Formatting Options
Reset					=\033[0m
Bold					=\033[1m
Dim						=\033[2m
Underline				=\033[4m
Blink					=\033[5m
Reverse					=\033[7m
Hidden					=\033[8m
StrikeThrough			=\033[9m
DoubleUnderline			=\033[21m
Framed					=\033[51m
Encircled				=\033[52m
Overlined				=\033[53m
Del 					=\033[1A\033[K
Clear					=\033[2K
Hide_cursor 			=\033[?25l
Show_cursor 			=\033[?25h
### ------------------------------ ###

### ---------- LINUX ---------- ###
CC_LIN			= cc

### ---------- OTHERS ---------- ###
NAME			= minishell
BONUS			=
CFLAGS			= -Wall -Wextra -Werror
INCLUDE			= include
LIBS			= libs/libft/libft.a
OTHERFLAGS		= -lreadline

### ---------- FILES ---------- ###
MAIN		= main.c
SRC			= src/errors.c src/free.c src/utils.c
BONUS_MAIN	=
BONUS_SRC	=
OBJ = ${SRC:.c=.o}
BONUS_OBJ = ${BONUS_SRC:.c=.o}

### ---------- FUNCTIONS ---------- ###
all: $(LIBS) $(NAME)

$(LIBS):
	@echo "$(Bright_Green)$(Blink)Compiling libft...$(Reset)"
	@make -C libs/libft > /dev/null 2>&1
	@echo "$(Del)"
	@echo "$(Del)$(Bright_Green)libft compiled successfully.$(Reset)"

.c.o:
	@${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	@$(CC_LIN) $(OBJ) $(MAIN) $(CFLAGS) $(OTHERFLAGS) -I$(INCLUDE) $(LIBS) -o $@
	@echo "$(Bright_Green)$@ compiled successfully.$(Reset)"


$(BONUS): $(BONUS_OBJ)
	@$(CC_LIN) $(BONUS_SRC) $(BONUS_MAIN) $(CFLAGS)  -I$(INCLUDE) $(LIBS) -o $@
	@echo "$(Bright_Green)$@ compiled successfully.$(Reset)"
##

bonus: $(BONUS)


clean:
	@make fclean -C libs/libft > /dev/null 2>&1
	@echo "$(Bright_Red)libft removed!$(Reset)"
	@rm -f $(OBJ)
	@echo "$(Bright_Red)Object files removed$(Reset)"


fclean:	clean
	@rm -f $(NAME)
	@echo "$(Bright_Red)$(NAME) removed!$(Reset)"
	@rm -f $(BONUS)
	@echo "$(Bright_Red)$(BONUS) removed!$(Reset)"
	@echo "$(Bright_Green)All removed successfully$(Reset)"

re: fclean all

.phony: all bonus fclean clean re
