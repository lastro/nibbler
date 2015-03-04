echo "1. Creation de la lib dynamique QT"
echo "  - g++ -c Qt/src/lib.cpp Qt/src/window.cpp"
g++ -c Qt/src/lib.cpp Qt/src/window.cpp
echo "  - g++ -shared -o lib.so lib.o window.o"
g++ -shared -o lib.so lib.o window.o

echo "2. Compilation du programme"
echo "  - g++ main/src/main.cpp main/src/Element.cpp main/src/Lib.cpp"
g++ main/src/main.cpp main/src/Element.cpp main/src/Lib.cpp
