#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/20 18:11:53 by rnicolas          #+#    #+#              #
#    Updated: 2015/03/20 18:49:33 by rnicolas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = nibbler

CC = g++

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I includes

LIBDIR = SFML SDL

LIB = $(LIBDIR:%=%.dylib)

SRCDIR = ./src/

OBJDIR = ./obj/

SRC =	Element.cpp\
		GameState.cpp\
		Lib.cpp\
		algo.cpp\
		main.cpp

OBJ = $(SRC:%.cpp=%.o)

OBJ_LIST = $(addprefix $(OBJDIR), $(OBJ))

all: $(LIB) $(NAME)

$(NAME): $(OBJ_LIST)
	$(CC) -Wl,-rpath,$(shell pwd) -o $@ $(OBJ_LIST)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

%.dylib: ../%
	make -C $<
	cp $</$@ .

clean:
	make -C ../SFML clean
	make -C ../SDL clean
	/bin/rm -fr $(OBJ_LIST)

fclean: clean
	rm -f $(LIB)
	rm -f ../SFML/SFML.dylib
	rm -f ../SDL/SDL.dylib
	rm -f $(NAME)

re: fclean all
