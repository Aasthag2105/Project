DrawBoard.o: DrawBoard.cpp
	g++ -pedantic-errors -std=c++11 -c $^

main.o: main.cpp
	g++ -c $^

Game: main.o DrawBoard.o
	g++ -pedantic-errors -std=c++11 $^ -o $@

clean:
	rm -f .*o

.PHONY: clean
