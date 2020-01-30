CFLAGS = -g -I include -std=c++14 -Wall -Werror -Wextra

main.cpp = ./src/main.cpp
StdioBoardView.cpp = ./src/StdioBoardView.cpp
Board.cpp = ./src/Board.cpp

main.o = ./bin/main.o
StdioBoardView.o = ./bin/StdioBoardView.o
Board.o = ./bin/Board.o

test.cpp = ./tests/test.cpp
BoardTest.cpp = ./tests/BoardTest.cpp
Test.cpp = ./tests/Test.cpp

test.o = ./bin/test.o
BoardTest.o = ./bin/BoardTest.o
Test.o = ./bin/Test.o

StdioBoardView.h = ./include/StdioBoardView.h
Board.h = ./include/Board.h
BoardTest.h = ./include/BoardTest.h
Test.h = ./include/Test.h

all: hw_02 test_hw_02

hw_02: bin $(main.o) $(StdioBoardView.o) $(Board.o)
	g++ $(main.o) $(StdioBoardView.o) $(Board.o) -o hw_02

test_hw_02: bin $(test.o) $(BoardTest.o) $(Test.o) $(Board.o)
	g++ $(test.o) $(BoardTest.o) $(Test.o) $(Board.o) -o test_hw_02

bin:
	mkdir bin

$(main.o): $(main.cpp) $(StdioBoardView.h) $(Board.h)
	g++ $(CFLAGS) -c $(main.cpp) -o $(main.o)

$(StdioBoardView.o): $(StdioBoardView.cpp) $(StdioBoardView.h)
	g++ $(CFLAGS) -c $(StdioBoardView.cpp) -o $(StdioBoardView.o)

$(Board.o): $(Board.cpp) $(Board.h)
	g++ $(CFLAGS) -c $(Board.cpp) -o $(Board.o)

$(test.o): $(test.cpp) $(BoardTest.h)
	g++ $(CFLAGS) -c $(test.cpp) -o $(test.o)

$(BoardTest.o): $(BoardTest.cpp) $(Board.h) $(BoardTest.h) $(Test.h)
	g++ $(CFLAGS) -c $(BoardTest.cpp) -o $(BoardTest.o)

$(Test.o): $(Test.cpp) $(Test.h)
	g++ $(CFLAGS) -c $(Test.cpp) -o $(Test.o)

clean:
	rm -rf bin hw_02 test_hw_02

