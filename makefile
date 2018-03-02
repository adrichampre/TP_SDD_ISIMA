
CC = gcc
CFLAGS = -W -Wall -g
LDFLAGS = -lm

OBJ = tp1main.o tp1.o liste.o

prog : $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o prog

liste.o : tp1.h liste.h liste.c
	$(CC) -c liste.c $(CFLAGS)

tp1.o : liste.h tp1.h tp1.c
	$(CC) -c tp1.c $(CFLAGS)