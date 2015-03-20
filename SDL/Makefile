#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/20 17:38:23 by rnicolas          #+#    #+#              #
#    Updated: 2015/03/20 18:50:39 by rnicolas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = SDL.dylib

CC = g++

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I includes -I ../main/includes -I ~/.brew/Cellar/sdl2/2.0.3/include/SDL2 -I ~/.brew/Cellar/sdl2_image/2.0.0_1/include/SDL2

LFLAGS = -L ~/.brew/lib -lSDL2 -lpng -lSDL2_image

SRCDIR = ./src/

OBJDIR = ./obj/

SRC = SDL.cpp

OBJ = $(SRC:%.cpp=%.o)

OBJ_LIST = $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_LIST)
	$(CC) -shared -o $@ $(OBJ_LIST) $(LFLAGS) -fPIC

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

clean:
	/bin/rm -fr $(OBJ_LIST)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
