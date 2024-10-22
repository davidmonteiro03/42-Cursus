# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 10:09:29 by dcaetano          #+#    #+#              #
#    Updated: 2024/10/22 10:39:15 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === COMMANDS =============================================================== #
RM            = rm
AR_RCS        = ar rcs
MKDIR         = mkdir
CXX           = c++
# === DIRECTORIES ============================================================ #
SRCS_DIR      = srcs
OBJS_DIR      = objs
# === EXTENSIONS ============================================================= #
CPP_EXTENSION = .cpp
HPP_EXTENSION = .hpp
OBJ_EXTENSION = .o
# === FILES ================================================================== #
NAME          = $(PROGRAM_NAME)
INCS          = $(addsuffix $(HPP_EXTENSION), \
                            $(CLASSES))
SRCS          = $(addsuffix $(CPP_EXTENSION), \
                            $(CLASSES))
OBJS          = $(patsubst %$(CPP_EXTENSION), \
                            $(OBJS_DIR)/$(SRCS_DIR)/%$(OBJ_EXTENSION), \
                            $(SRCS))
MAIN_SRC      = main$(CPP_EXTENSION)
MAIN_OBJ      = $(patsubst %$(CPP_EXTENSION), \
                            $(OBJS_DIR)/%$(OBJ_EXTENSION), \
                            $(MAIN_SRC))
LIB           = $(NAME).a
# === FLAGS ================================================================== #
RM_FLAGS      = -rf
MKDIR_FLAGS   = -p
CXX_FLAGS     = -Wall -Wextra -Werror -pedantic -std=c++98
# === PROJECT ================================================================ #
PROGRAM_NAME  = btc
CLASSES       = BitcoinExchange
LIB_NAME      = $(PROGRAM_NAME).a
# === RULES ================================================================== #
all: $(NAME)

$(OBJS_DIR)/$(SRCS_DIR)/%$(OBJ_EXTENSION): %$(CPP_EXTENSION)
	$(MKDIR) $(MKDIR_FLAGS) $(dir $@)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(OBJS_DIR)/%$(OBJ_EXTENSION): %$(CPP_EXTENSION)
	$(MKDIR) $(MKDIR_FLAGS) $(dir $@)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(LIB): $(OBJS)
	$(AR_RCS) $(LIB) $(OBJS)

$(NAME): $(LIB) $(MAIN_OBJ)
	$(CXX) $(CXX_FLAGS) $(MAIN_OBJ) $(LIB) -o $(NAME)

clean:
	$(RM) $(RM_FLAGS) $(OBJS_DIR)

fclean: clean
	$(RM) $(RM_FLAGS) $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
