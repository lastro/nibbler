#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/20 17:38:23 by rnicolas          #+#    #+#              #
#    Updated: 2015/03/20 17:59:17 by rnicolas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = SFML.dylib

CC = g++

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I includes -I ../main/includes -I ~/.brew/Cellar/sfml/2.2/include

LFLAGS = -L ~/.brew/Cellar/sfml/2.2/lib -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR = ./src/

OBJDIR = ./obj/

SRC = SFMLLib.cpp

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