echo "1. Creation de la lib dynamique ncruses"
echo "  - g++ -c Ncurses/src/lib.cpp Ncurses/src/window.cpp"
g++ -c -fPIC Ncurses/src/lib.cpp Ncurses/src/window.cpp
echo "  - g++ -shared -o ncurses.so lib.o window.o -lncurses"
g++ -shared -o ncurses.so lib.o window.o -lncurses

#echo "2. Compilation du programme"
#echo "  - g++ main/src/main.cpp main/src/Element.cpp main/src/Lib.cpp"
#g++ -ldl -std=c++11 main/src/main.cpp main/src/Element.cpp main/src/Lib.cpp main/src/GameState.cpp
