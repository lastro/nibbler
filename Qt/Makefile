#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 15:03:15 by gmangin           #+#    #+#              #
#    Updated: 2015/03/03 16:36:38 by gmangin                                   #
#                                                                              #
#******************************************************************************#

NAME = lib.so

SRC = src/window.cpp

FLAGS = -shared

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
		g++ -o $@ -c $< $(FLAGS)

$(NAME): $(OBJ)
		g++ $(OBJ) -o $(NAME)

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
