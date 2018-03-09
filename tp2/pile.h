#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elt_t;

typedef struct pile
{
	int taille;
	int indice;
	elt_t *val;
}pile_t;

void EMPILER(pile_t *p_pile, int val);
int DEPILER(pile_t *p_pile);
int VIDE(pile_t *p);