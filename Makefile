output.o: DrawBoard.cpp
	g++ -pedantic-errors -std=c++11 -c $<
	
main.o: main.cpp
	g++ -c main.cpp
	
Game:main.o output.o
	g++ -pedantic-errors -std=c++11 -o $@
	
clean:
	 rm - f .*o
