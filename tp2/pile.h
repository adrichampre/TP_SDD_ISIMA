#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elt_t;

typedef struct pile
{
	int taille;
	int nb_elt;
	elt_t *val;
}pile_t;

int Empiler(pile_t * p_pile, int val);
int Depiler(pile_t * p_pile, elt_t * e);
int Vide_Pile(pile_t * p);
int Pleine_Pile(pile_t * p);
void AfficherPile(pile_t * p);
pile_t * InitPile(int n);
void LiberePile(pile_t * p);