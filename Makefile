CC = g++
LIB = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system 
CFLAGS = --std=c++17 -Wall -Werror -pedantic
LINT_FLAGS = --linelength=180 --extensions=hpp,cpp

all: Sokoban

Sokoban: Sokoban.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
	
Sokoban.o: Sokoban.cpp Sokoban.hpp 
	$(CC) $(CFLAGS) -c $^

lint: CPPLINT.cfg
	cpplint $(LINT_FLAGS) --recursive .

clean:
	rm *.o Sokoban