#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 15:03:15 by gmangin           #+#    #+#              #
#    Updated: 2015/03/04 20:07:29 by gmangin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = a.out

SRC =	main/src/main.cpp		\
		main/src/init_game.cpp	\
		main/src/Element.cpp

FLAGS =

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
