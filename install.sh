
echo "Brew Update";
brew update;
echo "Done";

echo "brew install SDL2";
brew install sdl2;

echo "brew install Qt";
brew install Qt;

echo "cmake . -G 'Unix Makefiles'"
cmake . -G "Unix Makefiles";

echo "Setting variables in CMakeCache.txt"

echo "SDL2_INCLUDEDIR:FILEPATH="$HOME"/.brew/Cellar/sdl2/2.0.3/include/SDL2" >> CMakeCache.txt;
echo "SDL2_LIBRARYDIR:FILEPATH="$HOME"/.brew/Cellar/sdl2/2.0.3/lib" >> CMakeCache.txt;
echo "SDL2_ROOT:FILEPATH="$HOME"/.brew/Cellar/sdl2" >> CMakeCache.txt;

echo "make project"
make;