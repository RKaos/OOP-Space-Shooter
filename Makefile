CXX=g++
CXXFLAGS=-I"C:\Users\great\Documents\libraries\SFML-2.5.1\include"
LDFLAGS=-L"C:\Users\great\Documents\libraries\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: all clean

all: sfml-app

sfml-app: main.o
	$(CXX) main.o -o sfml-app $(LDFLAGS)

main.o: main.cpp always_build
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

always_build:
	-rm -f main.o

run: sfml-app
	./sfml-app

clean:
	rm -f main.o sfml-app