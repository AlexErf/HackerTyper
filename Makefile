
CC=cc
FL=-lncurses

all: HackerTyper

HackerTyper: HackerTyper.o
	$(CC) HackerTyper.o -o HackerTyper $(FL)

HackerTyper.o: HackerTyper.c
	$(CC) -c HackerTyper.c

clean:
	rm *.o HackerTyper
