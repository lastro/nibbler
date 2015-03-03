
echo "Brew Update";
brew update;
echo "Done";

echo "brew install boost";
brew install boost;

echo "cmake . -G 'Unix Makefiles'"
cmake . -G "Unix Makefiles";

echo "Setting variables in CMakeCache.txt"
echo "BOOST_INCLUDEDIR:FILEPATH="$HOME"/.brew/Cellar/boost/1.57.0/include" >> CMakeCache.txt;
echo "BOOST_LIBRARYDIR:FILEPATH="$HOME"/.brew/Cellar/boost/1.57.0/lib" >> CMakeCache.txt;
echo "BOOST_ROOT:FILEPATH="$HOME"/.brew/Cellar/boost" >> CMakeCache.txt;

echo "cmake . -G 'Unix Makefiles' with new variables"
cmake . -G "Unix Makefiles";

echo "make project"
make;