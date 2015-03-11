all:
	g++ -g -Wall -Werror -Wextra -c ../SDL/src/SDL.cpp -I ../SDL/includes -I includes -I ~/.brew/Cellar/sdl2/2.0.3/include/SDL2 -I ~/.brew/Cellar/sdl2_image/2.0.0_1/include/SDL2
	g++ -g -shared -o SDL.dylib SDL.o -L ~/.brew/Cellar/sdl2/2.0.3/lib -lSDL2  ~/.brew/Cellar/sdl2_image/2.0.0_1/lib/libSDL2_image.a -fPIC
	g++ -g -c -Wall -Werror -Wextra src/*.cpp -I includes
	g++ -g -o nibbler algo.o main.o Lib.o GameState.o