# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 02:11:55 by preis-ne          #+#    #+#              #
#    Updated: 2024/09/06 13:10:05 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- COLORS ----------------------------------------------------------------- #
# --- Normal --- #
RED_COLOR              = \033[0;31m
GREEN_COLOR            = \033[0;32m
YELLOW_COLOR           = \033[0;33m
BLUE_COLOR             = \033[0;34m
MAGENTA_COLOR          = \033[0;35m
CYAN_COLOR             = \033[0;36m
WHITE_COLOR            = \033[0;37m
# --- Bold --- #
RED_COLOR_BOLD         = \033[1;31m
GREEN_COLOR_BOLD       = \033[1;32m
YELLOW_COLOR_BOLD      = \033[1;33m
BLUE_COLOR_BOLD        = \033[1;34m
MAGENTA_COLOR_BOLD     = \033[1;35m
CYAN_COLOR_BOLD        = \033[1;36m
WHITE_COLOR_BOLD       = \033[1;37m
# --- Intensed --- #
RED_COLOR_HIGH         = \033[0;91m
GREEN_COLOR_HIGH       = \033[0;92m
YELLOW_COLOR_HIGH      = \033[0;93m
BLUE_COLOR_HIGH        = \033[0;94m
MAGENTA_COLOR_HIGH     = \033[0;95m
CYAN_COLOR_HIGH        = \033[0;96m
WHITE_COLOR_HIGH       = \033[0;97m
# --- Bold-Intensed --- #
RED_COLOR_BOLDHIGH     = \033[1;91m
GREEN_COLOR_BOLDHIGH   = \033[1;92m
YELLOW_COLOR_BOLDHIGH  = \033[1;93m
BLUE_COLOR_BOLDHIGH    = \033[1;94m
MAGENTA_COLOR_BOLDHIGH = \033[1;95m
CYAN_COLOR_BOLDHIGH    = \033[1;96m
WHITE_COLOR_BOLDHIGH   = \033[1;97m
# --- Blinking --- #
RED_COLOR_BLINK        = \033[5;31m
GREEN_COLOR_BLINK      = \033[5;32m
YELLOW_COLOR_BLINK     = \033[5;33m
BLUE_COLOR_BLINK       = \033[5;34m
MAGENTA_COLOR_BLINK    = \033[5;35m
CYAN_COLOR_BLINK       = \033[5;36m
WHITE_COLOR_BLINK      = \033[5;37m
# --- Reset --- #
RESET_COLOR            = \033[0m
# --- COMMANDS --------------------------------------------------------------- #
CC                     = cc
RM                     = rm
MKDIR                  = mkdir
AR                     = ar rcs
PRINTF                 = printf
# --- DISPLAY FORMAT --------------------------------------------------------- #
SIZE_1                 = 70
SIZE_2                 = 10
# --- DIRECTORIES ------------------------------------------------------------ #
INCLUDES_DIR           = includes
SOURCES_DIR            = sources
OBJECTS_DIR            = objects
# --- FLAGS ------------------------------------------------------------------ #
CFLAGS                 = -Wall -Wextra -Werror
RMFLAGS                = -rf
MKDIRFLAGS             = -p
# --- FILES ------------------------------------------------------------------ #
# --- Sources --- #
SOURCES                = $(addprefix $(SOURCES_DIR)/, \
                           ft_atoi.c ft_bzero.c ft_calloc.c ft_case_c.c \
                           ft_case_di.c ft_case_p.c ft_case_percent.c \
                           ft_case_s.c ft_case_u.c ft_case_xx.c ft_flags.c \
                           ft_isalnum.c ft_isalpha.c ft_isascii.c \
                           ft_isdigit.c ft_isprint.c ft_itoa.c \
                           ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
                           ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
                           ft_lstmap.c ft_lstnew.c ft_lstsize.c \
                           ft_manipulations_di.c ft_manipulations_numbers.c \
                           ft_manipulations_numbers_two.c \
                           ft_manipulations_strings.c \
                           ft_manipulations_strings_two.c \
                           ft_manipulations_u.c ft_manipulations_xx.c \
                           ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
                           ft_memset.c ft_printf.c ft_putchar_fd.c \
                           ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
                           ft_split.c ft_strchr.c ft_strdup.c \
                           ft_striteri.c ft_strjoin.c ft_strlcat.c \
                           ft_strlcpy.c ft_strlen.c ft_strmapi.c \
                           ft_strncmp.c ft_strnstr.c ft_strrchr.c \
                           ft_strtrim.c ft_substr.c ft_tolower.c \
                           ft_toupper.c get_next_line.c)
# --- Objects --- #
OBJECTS                = $(patsubst \
                           $(SOURCES_DIR)/%.c, \
                           $(OBJECTS_DIR)/%.o, \
                           $(SOURCES))
# --- PROJECT ---------------------------------------------------------------- #
NAME                   = libft
# --- RULES ------------------------------------------------------------------ #
all: $(NAME).a

$(NAME).a: $(OBJECTS)
	@$(AR) $@ $(OBJECTS)
	@$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(GREEN_COLOR)created$(RESET_COLOR)\n" $(NAME) $(NAME)/$(NAME).a

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(MKDIR) $(MKDIRFLAGS) $(OBJECTS_DIR)
	@$(PRINTF) "\r\033[K$(YELLOW_COLOR). $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(YELLOW_COLOR)Compiling $(CYAN_COLOR)$(NAME)/$<$(RESET_COLOR)" $(NAME)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@
	@$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(GREEN_COLOR)compiled$(RESET_COLOR)\n" $(NAME) $(NAME)/$<

clean:
	@for file in $(OBJECTS); do \
		if [ -f $$file ]; then \
			$(PRINTF) "\r\033[K$(YELLOW_COLOR). $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(RED_COLOR)Removing $(CYAN_COLOR)$(NAME)/$(OBJECTS_DIR)$(RESET_COLOR)" $(NAME); \
			$(RM) $(RMFLAGS) $(OBJECTS_DIR); \
			$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(RED_COLOR)removed$(RESET_COLOR)\n" $(NAME) $(NAME)/$(OBJECTS_DIR); \
			break; \
		fi; \
	done

fclean: clean
	@if [ -f $(NAME).a ]; then \
		$(PRINTF) "\r\033[K$(YELLOW_COLOR). $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(RED_COLOR)Removing $(CYAN_COLOR)$(NAME)/$(NAME).a$(RESET_COLOR)" $(NAME); \
		$(RM) $(RMFLAGS) $(NAME).a; \
		$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(RED_COLOR)removed$(RESET_COLOR)\n" $(NAME) $(NAME)/$(NAME).a; \
	fi

re: fclean all

.PHONY: all clean fclean re
