CC = gcc
CFLAGS = -W -Wall -pedantic -g
LDFLAGS = -lm

OBJ = testarbre.o arbre.o pile.o file.o

prog : $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o prog

file.o : file.h file.c noeud.h
	$(CC) -c file.c $(CFLAGS)

pile.o : pile.h pile.c noeud.h
	$(CC) -c pile.c $(CFLAGS)
	
arbre.o : noeud.h arbre.c pile.h arbre.h
	$(CC) -c arbre.c $(CFLAGS)

testarbre.o : arbre.h arbre.c testarbre.c
	$(CC) -c testarbre.c $(CFLAGS)

clean:
		rm -rf *.o

mrproper: clean
		rm -rf prog
