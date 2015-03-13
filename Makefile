
CC=cc
FL=-lncurses

all: HackerTyper

HackerTyper: HackerTyper.o
	$(CC) HackerTyper.o -o HackerTyper

HackerTyper.o: HackerTyper.c
	$(CC) $(FL) -c HackerTyper.c

clean:
	rm *.o HackerTyper
