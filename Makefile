
CC=cc

all: HackerTyper

HackerTyper: HackerTyper.o
	$(CC) HackerTyper.o -o HackerTyper

HackerTyper.o: HackerTyper.c
	$(CC) -c HackerTyper.c

clean:
	rm *.o HackerTyper
