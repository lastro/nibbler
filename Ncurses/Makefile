#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 15:03:15 by gmangin           #+#    #+#              #
#    Updated: 2015/03/10 02:42:17 by gmangin                                   #
#                                                                              #
#******************************************************************************#

NAME = ../ncurses.so

SRC = src/window.cpp

FLAGS = -fPIC

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
