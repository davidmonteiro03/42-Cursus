# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:20:46 by dcaetano          #+#    #+#              #
#    Updated: 2024/11/09 19:17:07 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === COMMANDS =============================================================== #
AR_RCS    = ar rcs
CPP       = c++
MK        = mkdir
RM        = rm
# === DIRECTORIES ============================================================ #
INCS_D    = includes
SRCS_D    = srcs
OBJS_D    = objs
MAND_D    = mandatory
BONS_D    = bonus
EXEC_D    = ex01
IMGS_D    = images
# === EXTENSIONS ============================================================= #
CPP_EXT   = .cpp
HPP_EXT   = .hpp
OBJ_EXT   = .o
# === FILES ================================================================== #
# --- Mandatory --- #
CLSS_M    = Vector2 Graph
SRCS_M    = $(addprefix $(EXEC_D)/$(MAND_D)/$(SRCS_D)/, \
                        $(addsuffix $(CPP_EXT), \
                                    $(CLSS_M)))
MAIN_M    = $(EXEC_D)/main$(CPP_EXT)
# --- Bonus --- #
CLSS_B    = Vector2 Graph
SRCS_B    = $(addprefix $(EXEC_D)/$(BONS_D)/$(SRCS_D)/, \
                        $(addsuffix $(CPP_EXT), \
                                    $(CLSS_B)))
MAIN_B    = $(EXEC_D)/bonus$(CPP_EXT)
# --- Common --- #
ifeq ($(MAKECMDGOALS),bonus)
	INCS  = $(addprefix $(EXEC_D)/$(BONS_D)/$(INCS_D)/, \
                        $(addsuffix $(HPP_EXT), \
                                    $(CLSS_B)))
	OBJS  = $(patsubst $(EXEC_D)/$(BONS_D)/$(SRCS_D)/%$(CPP_EXT), \
                       $(OBJS_D)/$(BONS_D)/%$(OBJ_EXT), \
                       $(SRCS_B))
	MAIN = $(patsubst $(EXEC_D)/%$(CPP_EXT), \
                       $(OBJS_D)/%$(OBJ_EXT), \
                       $(MAIN_B))
else
	INCS  = $(addprefix $(EXEC_D)/$(MAND_D)/$(INCS_D)/, \
                        $(addsuffix $(HPP_EXT), \
                                    $(CLSS_M)))
	OBJS  = $(patsubst $(EXEC_D)/$(MAND_D)/$(SRCS_D)/%$(CPP_EXT), \
                       $(OBJS_D)/$(MAND_D)/%$(OBJ_EXT), \
                       $(SRCS_M))
	MAIN = $(patsubst $(EXEC_D)/%$(CPP_EXT), \
                       $(OBJS_D)/%$(OBJ_EXT), \
                       $(MAIN_M))
endif
# === FLAGS ================================================================== #
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
MK_FLAGS  = -p
RM_FLAGS  = -rfv
# === PROJECT ================================================================ #
NAME = graph
LIB = $(NAME).a
# === RULES ================================================================== #
all: $(NAME)

bonus: $(NAME)

$(OBJS_D)/$(MAND_D)/%$(OBJ_EXT): $(EXEC_D)/$(MAND_D)/$(SRCS_D)/%$(CPP_EXT) $(INCS)
	@$(MK) $(MK_FLAGS) $(dir $@)
	@$(CPP) $(CPP_FLAGS) -c $< -o $@

$(OBJS_D)/$(BONS_D)/%$(OBJ_EXT): $(EXEC_D)/$(BONS_D)/$(SRCS_D)/%$(CPP_EXT) $(INCS)
	@$(MK) $(MK_FLAGS) $(dir $@)
	@$(CPP) $(CPP_FLAGS) -c $< -o $@

$(OBJS_D)/%$(OBJ_EXT): $(EXEC_D)/%$(CPP_EXT) $(INCS)
	@$(MK) $(MK_FLAGS) $(dir $@)
	@$(CPP) $(CPP_FLAGS) -c $< -o $@

$(LIB): $(OBJS)
	@$(AR_RCS) $(LIB) $(OBJS)

$(NAME): $(LIB) $(MAIN)
	@$(CPP) $(CPP_FLAGS) $(MAIN) $(LIB) -lcairo -o $(NAME)
	@$(MK) $(MK_FLAGS) images

clean:
	@$(RM) $(RM_FLAGS) $(OBJS_D)

fclean: clean
	@$(RM) $(RM_FLAGS) $(LIB) $(NAME) $(IMGS_D)

re: fclean all

.PHONY: all bonus clean fclean re
