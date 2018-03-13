
CC = gcc
CFLAGS = -W -Wall -pedantic -g
LDFLAGS = -lm

OBJ = main.o pile.o tp2.o file.o

prog : $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o prog

liste.o : tp1.h liste.h liste.c
	$(CC) -c liste.c $(CFLAGS)

tp1.o : liste.h tp1.h tp1.c
	$(CC) -c tp1.c $(CFLAGS)

clean:
		rm -rf *.o

mrproper: clean
		rm -rf prog