#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 15:03:15 by gmangin           #+#    #+#              #
#    Updated: 2015/03/09 11:46:11 by gmangin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ../ncurses.so

SRC = src/window.cpp

FLAGS = -shared

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
		g++ -o $@ -c $< $(FLAGS)

$(NAME): $(OBJ)
		g++ -shared $(OBJ) -o $(NAME) -lncurses

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
