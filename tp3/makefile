CC = gcc
CFLAGS = -W -Wall -pedantic -g
LDFLAGS = -lm

OBJ = testarbre.o arbre.o pile.o 

prog : $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o prog
	
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
