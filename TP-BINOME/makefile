
CC = gcc
CFLAGS = -W -Wall -v -g

all: tp1main.o tp1.o
	$(CC) tp1main.o tp1.o -o tp1

tp1main.o: tp1main.c tp1.c
	$(CC) -c tp1main.c -o tp1main.o

tp1.o: tp1.c
	$(CC) -c tp1.c -o tp1.o

clean:
		rm -rf *.o

mrproper: clean
		rm -rf tp1

