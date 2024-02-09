# Makefile for libftprintf.a

RED			= \033[1;91m
GREEN		= \033[1;92m
YELLOW		= \033[1;93m
CYAN		= \033[1;96m
RESET		= \033[1;0m

SRCS		= ft_converthex.c \
				ft_format.c \
				ft_len.c \
				ft_printf.c \
				ft_putchar.c \
				ft_putnbr_base.c \
				ft_putnbr.c \
				ft_putptr.c \
				ft_putstr.c

SRCS_BONUS	= ft_addchar_bonus.c \
				ft_addflags_bonus.c \
				ft_addnbr_base_bonus.c \
				ft_addnbr_bonus.c \
				ft_addptr_bonus.c \
				ft_addstr_bonus.c \
				ft_check_bonus.c \
				ft_check_flag_bonus.c \
				ft_check_tab_bonus.c \
				ft_checkdec_bonus.c \
				ft_checkhex_bonus.c \
				ft_checkint_bonus.c \
				ft_converthex.c \
				ft_datanew_bonus.c \
				ft_findbug_bonus.c \
				ft_fixbughex_bonus.c \
				ft_fixbugint_bonus.c \
				ft_format_bonus.c \
				ft_getformat_bonus.c \
				ft_len.c \
				ft_ltoa_bonus.c \
				ft_printarg_bonus.c \
				ft_printdata_bonus.c \
				ft_printf_bonus.c \
				ft_putchar.c \
				ft_removenode_bonus.c \
				ft_truncate_bonus.c \
				ft_vtoc_bonus.c

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

NAME		= libftprintf.a
AR			= ar rcs
LIB			= ranlib
RM			= rm -rf
CC			= cc
FLAGS		= -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
	@echo "$(YELLOW)Compiling $(CYAN)$<$(RESET)..."

$(NAME): $(OBJS) libft/libft.a
	@cp libft/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@$(LIB) $(NAME)
	@echo "$(CYAN)$(NAME) $(GREEN)created$(RESET)!"

bonus: $(OBJS_BONUS) libft/libft.a
	@cp libft/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJS_BONUS)
	@$(LIB) $(NAME)
	@echo "$(CYAN)$(NAME) $(GREEN)created$(RESET)!"

libft/libft.a:
	@make -s -C libft bonus > /dev/null 2>&1

so:
	@${CC} -nostartfiles -fPIC ${FLAGS} ${SRCS} ${SRCS_BONUS}
	@gcc -nostartfiles -shared -o libft.so ${OBJS} ${OBJS_BONUS}

clean:
	@make -s -C libft clean > /dev/null 2>&1
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "$(CYAN)Objects $(RED)removed$(RESET)!"

fclean: clean
	@make -s -C libft fclean > /dev/null 2>&1
	@$(RM) $(NAME)
	@echo "$(CYAN)$(NAME) $(RED)removed$(RESET)!"

re: fclean all

.PHONY: all clean fclean re
