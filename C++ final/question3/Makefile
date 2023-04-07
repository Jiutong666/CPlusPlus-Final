.default: all

all: red7

clean:
	rm -f red7 *.o

red7: Card.o main.o DeckVector.o DeckDeQue.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
