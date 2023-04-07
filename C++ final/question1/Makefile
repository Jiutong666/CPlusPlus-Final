.default: all

PROGRAMS=question1

all: $(PROGRAMS)

clean:
	rm -rf $(PROGRAMS) *.o *.dSYM

question1: main.o Card.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
