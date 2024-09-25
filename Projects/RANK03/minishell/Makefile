# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 11:25:19 by dcaetano          #+#    #+#              #
#    Updated: 2024/09/25 12:19:58 by dcaetano         ###   ########.fr        #
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
AR                     = ar rcs
BASH                   = bash
CC                     = cc
ECHO                   = echo
MKDIR                  = mkdir
PRINTF                 = printf
RM                     = rm
VALGRIND               = valgrind
# --- DISPLAY FORMAT --------------------------------------------------------- #
SIZE_1                 = 70
SIZE_2                 = 10
# --- DIRECTORIES ------------------------------------------------------------ #
INCLUDES_DIR           = includes
SOURCES_DIR            = sources
OBJECTS_DIR            = objects
# --- EXTENSIONS ------------------------------------------------------------- #
CEXTENSION             = .c
# --- FLAGS ------------------------------------------------------------------ #
CFLAGS                 = -Wall -Wextra -Werror
FTMAKEFLAGS            = -s -C
MKDIRFLAGS             = -p
READLINEFLAGS          = -lreadline
RMFLAGS                = -rf
VALGRINDFLAGS          = -s --suppressions=$(READLINE_SUPP) \
                         --tool=memcheck --leak-check=full \
                         --show-leak-kinds=all --track-origins=yes \
                         --track-fds=yes --show-below-main=no \
                         --log-file=$(LEAKS_LOG)
# --- FILES ------------------------------------------------------------------ #
LEAKS_LOG              = leaks.log
READLINE_SUPP          = readline.supp
BUILTINS_SOURCES       = cd cdspecific changedir echo execute execve exit \
                         export getpath pwd unset
CMDS_SOURCES           = append args checkfiles clear controlfds execute \
                         first heredoc last new nopipe openclosefds parse \
                         print pushback pushfront redin redout size
FILES_SOURCES          = clear first last lastin lastout new print pushback \
                         pushfront
DISPLAY_SOURCES        = case_c case_di case_p case_percent case_s \
                         case_u case_xx flags fprintf manipulations_di \
                         manipulations_numbers \
                         manipulations_numbers_two \
                         manipulations_strings \
                         manipulations_strings_two manipulations_u \
                         manipulations_xx
ENV_SOURCES            = clear display init underscoreup unset
EXP_SOURCES            = clear execute init print
PARSE_SOURCES          = expand heredocexpand quotes readline somefix \
                         vars
SHELL_SOURCES          = backup hardreset init softreset
SIGNALS_SOURCES        = handler status
SYNTAX_SOURCES         = error parse unexpected_eof_match
TEMP_SOURCES           = clear init
TOKENS_SOURCES         = clear first getoper gettext isoper last new \
                         parse print pushback pushfront size
UTILS_SOURCES          = atott exportvalidop freestrs isspace joinfree \
                         laststr listtoarray shellatoi strcmp strconstruct \
                         strflex syscallerror tokenstostrs
VARS_SOURCES           = clear copy delone dup export first getvalue last \
                         new new2 pushback pushfront remove resetvalue size \
                         sort unset
LIB_DATA               = $(addprefix $(SOURCES_DIR)/, \
                           $(addprefix builtins/, \
                             $(addsuffix $(CEXTENSION), \
                           $(BUILTINS_SOURCES))) \
                           $(addprefix cmds/, \
                             $(addsuffix $(CEXTENSION), \
                           $(CMDS_SOURCES))) \
                           $(addprefix display/, \
                             $(addsuffix $(CEXTENSION), \
                           $(DISPLAY_SOURCES))) \
                           $(addprefix exp/, \
                             $(addsuffix $(CEXTENSION), \
                           $(EXP_SOURCES))) \
                           $(addprefix env/, \
                             $(addsuffix $(CEXTENSION), \
                           $(ENV_SOURCES))) \
                           $(addprefix files/, \
                             $(addsuffix $(CEXTENSION), \
                           $(FILES_SOURCES))) \
                           $(addprefix parse/, \
                             $(addsuffix $(CEXTENSION), \
                           $(PARSE_SOURCES))) \
                           $(addprefix shell/, \
                             $(addsuffix $(CEXTENSION), \
                           $(SHELL_SOURCES))) \
                           $(addprefix signals/, \
                             $(addsuffix $(CEXTENSION), \
                           $(SIGNALS_SOURCES))) \
                           $(addprefix syntax/, \
                             $(addsuffix $(CEXTENSION), \
                           $(SYNTAX_SOURCES))) \
                           $(addprefix temp/, \
                             $(addsuffix $(CEXTENSION), \
                           $(TEMP_SOURCES))) \
                           $(addprefix tokens/, \
                             $(addsuffix $(CEXTENSION), \
                           $(TOKENS_SOURCES))) \
                           $(addprefix utils/, \
                             $(addsuffix $(CEXTENSION), \
                           $(UTILS_SOURCES))) \
                           $(addprefix vars/, \
                             $(addsuffix $(CEXTENSION), \
                           $(VARS_SOURCES))))
MAIN_SOURCE            = main$(CEXTENSION)
LIB_OBJECTS            = $(patsubst \
                           $(SOURCES_DIR)/%.c, \
                           $(OBJECTS_DIR)/%.o, \
                           $(LIB_DATA))
MAIN_OBJECT            = $(OBJECTS_DIR)/$(MAIN_SOURCE:.c=.o)
INCLUDES               = consts headers minishell structs
HEADERS                = $(addsuffix .h, \
                           $(addprefix $(INCLUDES_DIR)/, \
                         $(INCLUDES)))
# --- LIBRARIES AND LINKS ---------------------------------------------------- #
LIBFT                  = libft
LIBMINI                = lib$(NAME).a
LIBS_LINKS             = -L$(LIBFT) $(LIBMINI) \
                              -lft
# --- PROJECT ---------------------------------------------------------------- #
NAME                   = minishell
READLINE_IGNORE        = add_history readline readline_internal_char \
                         rl_clear_history
PERMITTED_FUNCTIONS    = readline rl_clear_history rl_on_new_line \
                         rl_replace_line rl_redisplay add_history printf \
                         malloc free write access open read close fork wait \
                         waitpid wait3 wait4 signal sigaction sigemptyset \
                         sigaddset kill exit getcwd chdir stat lstat fstat \
                         unlink execve dup dup2 pipe opendir readdir \
                         closedir strerror perror isatty ttyname ttyslot \
                         ioctl getenv tcsetattr tcgetattr tgetent tgetflag \
                         tgetnum tgetstr tgoto tputs
# --- RULES ------------------------------------------------------------------ #
all: $(NAME)

$(NAME): $(LIB_OBJECTS) $(MAIN_OBJECT)
	@$(MAKE) $(FTMAKEFLAGS) $(LIBFT)
	@$(AR) $(LIBMINI) $(LIB_OBJECTS)
	@$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(GREEN_COLOR)created$(RESET_COLOR)\n" $(NAME) $(NAME)/$(LIBMINI)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $(MAIN_OBJECT) $(LIBS_LINKS) \
		$(READLINEFLAGS) -o $(NAME)
	@$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(GREEN_COLOR)created$(RESET_COLOR)\n" $(NAME) $(NAME)/$(NAME)

$(OBJECTS_DIR)/%.o: %.c $(HEADERS)
	@$(MKDIR) $(MKDIRFLAGS) $(dir $@)
	@$(PRINTF) "\r\033[K$(YELLOW_COLOR). $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(YELLOW_COLOR)Compiling $(CYAN_COLOR)$(NAME)/$<$(RESET_COLOR)" $(NAME)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@
	@$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(GREEN_COLOR)compiled$(RESET_COLOR)\n" $(NAME) $(NAME)/$<

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c $(HEADERS)
	@$(MKDIR) $(MKDIRFLAGS) $(dir $@)
	@$(PRINTF) "\r\033[K$(YELLOW_COLOR). $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(YELLOW_COLOR)Compiling $(CYAN_COLOR)$(NAME)/$<$(RESET_COLOR)" $(NAME)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@
	@$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(GREEN_COLOR)compiled$(RESET_COLOR)\n" $(NAME) $(NAME)/$<

clean:
	@$(MAKE) $(FTMAKEFLAGS) $(LIBFT) clean
	@for file in $(MAIN_OBJECT) $(LIB_OBJECTS); do \
		if [ -f $$file ]; then \
			$(PRINTF) "\r\033[K$(YELLOW_COLOR). $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(RED_COLOR)Removing $(CYAN_COLOR)$(NAME)/$(OBJECTS_DIR)$(RESET_COLOR)" $(NAME); \
			$(RM) $(RMFLAGS) $(OBJECTS_DIR); \
			$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(RED_COLOR)removed$(RESET_COLOR)\n" $(NAME) "$(NAME)/$(OBJECTS_DIR)"; \
			break; \
		fi; \
	done

fclean: clean
	@$(MAKE) $(FTMAKEFLAGS) $(LIBFT) fclean
	@if [ -f $(LIBMINI) ]; then \
		$(PRINTF) "\r\033[K$(YELLOW_COLOR). \
			$(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(RED_COLOR)Removing $(CYAN_COLOR)$(NAME)/$(LIBMINI)$(RESET_COLOR)" $(NAME); \
		$(RM) $(RMFLAGS) $(LIBMINI); \
		$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(RED_COLOR)removed$(RESET_COLOR)\n" $(NAME) $(NAME)/$(LIBMINI); \
	fi
	@if [ -f $(NAME) ]; then \
		$(PRINTF) "\r\033[K$(YELLOW_COLOR). \
			$(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(RED_COLOR)Removing $(CYAN_COLOR)$(NAME)/$(NAME)$(RESET_COLOR)" $(NAME); \
		$(RM) $(RMFLAGS) $(NAME); \
		$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(RED_COLOR)removed$(RESET_COLOR)\n" $(NAME) $(NAME)/$(NAME); \
	fi
	@if [ -f $(LEAKS_LOG) ]; then \
		$(PRINTF) "\r\033[K$(YELLOW_COLOR). \
			$(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(RED_COLOR)Removing $(CYAN_COLOR)$(NAME)/$(LEAKS_LOG)$(RESET_COLOR)" $(NAME); \
		$(RM) $(RMFLAGS) $(LEAKS_LOG); \
		$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(RED_COLOR)removed$(RESET_COLOR)\n" $(NAME) $(NAME)/$(LEAKS_LOG); \
	fi
	@if [ -f $(READLINE_SUPP) ]; then \
		$(PRINTF) "\r\033[K$(YELLOW_COLOR). \
			$(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(RED_COLOR)Removing $(CYAN_COLOR)$(NAME)/$(READLINE_SUPP)$(RESET_COLOR)" $(NAME); \
		$(RM) $(RMFLAGS) $(READLINE_SUPP); \
		$(PRINTF) "\r\033[K$(GREEN_COLOR)✓ $(CYAN_COLOR)%-$(SIZE_2)s$(WHITE_COLOR) | $(CYAN_COLOR)%-$(SIZE_1)s $(RED_COLOR)removed$(RESET_COLOR)\n" $(NAME) $(NAME)/$(READLINE_SUPP); \
	fi

re: fclean all

run: all
	@./$(NAME)

leaks: all readline
	@$(VALGRIND) $(VALGRINDFLAGS) ./$(NAME)

bash: all readline
	@$(VALGRIND) $(VALGRINDFLAGS) $(BASH)

readline:
	@if [ -f $(READLINE_SUPP) ]; then \
		$(RM) $(RMFLAGS) $(READLINE_SUPP); \
	fi
	@for i in $(READLINE_IGNORE); do \
		$(ECHO) "{"                >> $(READLINE_SUPP); \
		$(ECHO) "	leak $$i"      >> $(READLINE_SUPP); \
		$(ECHO) "	Memcheck:Leak" >> $(READLINE_SUPP); \
		$(ECHO) "	..."           >> $(READLINE_SUPP); \
		$(ECHO) "	fun:$$i"       >> $(READLINE_SUPP); \
		$(ECHO) "}"                >> $(READLINE_SUPP); \
	done

files:
	@echo "$(CYAN_COLOR)--- Repository content checking ---$(RESET_COLOR)"; \
		forbidden_files=$$(find * -type f -not -name "*.c" -a -not -name "*.h" -a -not -name "Makefile"); \
		if [ -z "$$forbidden_files" ]; then \
			echo "$(GREEN_COLOR)✓ No forbidden files were found.$(RESET_COLOR)"; \
		else \
			for file in $$forbidden_files; do \
				printf "$(RED_COLOR_BLINK)✗$(RESET_COLOR) $(RED_COLOR)Forbidden file: $$file$(RESET_COLOR)\n"; \
			done; \
		fi

norm:
	@echo "$(CYAN_COLOR)--- Norminette checking ---$(RESET_COLOR)"
	@for file in $(shell find . -name "*.c"); do \
		norminette $$file 1>/dev/null \
		&& echo "$(GREEN_COLOR)✓ $$file: OK$(RESET_COLOR)" \
		|| echo "$(RED_COLOR_BLINK)✗$(RESET_COLOR) $(RED_COLOR)$$file: KO$(RESET_COLOR)"; \
	done

funcs: all
	@echo "$(CYAN_COLOR)--- Forbidden functions checking ---$(RESET_COLOR)"
	@for func in $(shell nm -Puj --without-symbol-versions $(NAME) 2>/dev/null | grep -v '^_'); do \
		echo $(PERMITTED_FUNCTIONS) | tr ',' ' ' | tr ' ' '\n' | grep -v '^$$' | grep $$func > /dev/null; \
		if [ $$? != 0 ]; then \
			echo "$(RED_COLOR_BLINK)✗$(RESET_COLOR) $(RED_COLOR)$$func$(RESET_COLOR)"; \
		else \
			echo "$(GREEN_COLOR)✓ $$func$(RESET_COLOR)"; \
		fi \
	done

check: files norm funcs

.PHONY: all clean fclean re run leaks bash readline files norm funcs
