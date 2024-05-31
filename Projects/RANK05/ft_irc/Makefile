# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 19:12:17 by dcaetano          #+#    #+#              #
#    Updated: 2024/05/23 22:08:41 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
RM = rm -rf
AR = ar rcs

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -O3

INCS = ./includes/

NAME = ircserv
SRCS = ./main.cpp
OBJS = $(SRCS:.cpp=.o)

LIB = ircserv.a
SRCS_LIB = ./srcs/Server.cpp ./srcs/Client.cpp \
	./srcs/Channel.cpp ./srcs/utils.cpp ./srcs/Bot.cpp
OBJS_LIB = $(SRCS_LIB:.cpp=.o)

all: $(NAME)

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_LIB): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	$(CXX) $(CXXFLAGS) -I$(INCS) $(OBJS) $(LIB) -o $(NAME)

$(LIB): $(OBJS_LIB)
	$(AR) $(LIB) $(OBJS_LIB) $(OBJS_LIB)

clean:
	$(RM) $(OBJS_LIB) $(OBJS)

fclean: clean
	$(RM) $(LIB) $(NAME)

re: fclean all

.PHONY: all clean fclean re
