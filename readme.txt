Commands for compiling and running the sfml code
g++ -c main.cpp
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app


Windows:
g++ -c main.cpp -I"C:\Users\great\Documents\libraries\SFML-2.5.1\include"
g++ main.o -o sfml-app -L"C:\Users\great\Documents\libraries\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app