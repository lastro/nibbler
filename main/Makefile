all:
	g++  -Wall -Werror -Wextra -c ../SDL/src/SDL.cpp -I ../SDL/includes -I includes -I ~/.brew/Cellar/sdl2/2.0.3/include/SDL2 -I ~/.brew/Cellar/sdl2_image/2.0.0_1/include/SDL2
	g++  -shared -o SDL.dylib SDL.o ~/.brew/Cellar/sdl2_image/2.0.0_1/lib/libSDL2_image.a -L ~/.brew/lib -lSDL2 -lpng -fPIC
	g++  -Wall -Werror -Wextra -c ../SFML/src/SFMLLib.cpp -I ../SFML/includes -I includes -I ~/.brew/Cellar/sfml/2.2/include
	g++  -shared -o SFML.dylib SFMLLib.o -L ~/.brew/Cellar/sfml/2.2/lib -lsfml-graphics -lsfml-window -lsfml-system -fPIC
	g++  -c -Wall -Werror -Wextra src/*.cpp -I includes
	g++ -Wl,-rpath,$(shell pwd) -o nibbler algo.o main.o Lib.o GameState.o