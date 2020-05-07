DrawBoard.o: DrawBoard.cpp DrawBoard.h
	g++ -c DrawBoard.cpp
	
main.o: main.cpp DrawBoard.h
	g++ -c main.cpp
	
main: main.o DrawBoard.o
	g++ -pedantic-errors -std=c++11 main.o DrawBoard.o -o main
	
