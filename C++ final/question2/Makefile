.default: all

PROGRAMS=force

all: $(PROGRAMS)

clean:
	rm -rf $(PROGRAMS) *.o *.dSYM

force: main.o Force.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
