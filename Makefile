#******************************************************************************#
#                                                                              #
#                                                                              #
#    Makefile                                                                  #
#                                                                              #
#    By: gmangin <gaelle.mangin@hotmail.fr>                                    #
#                                                                              #
#    Created: 2015/03/02 12:18:45 by gmangin                                   #
#    Updated: 2015/03/02 15:00:02 by tlepetit         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = snake

SRC_DIR = main

SRC = $(SRC_DIR)/main.cpp

FLAGS = -Wall -Werror -Wextra

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
