#ifndef ARBRE_PERE
#define ARBRE_PERE

#include "arbre.h"

typedef struct arbrePere
{
	char c;
	struct arbrePere * vertical;
	struct arbrePere * horizontal;
	struct arbrePere * pere;
}ArbrePere_t;

void initArbrePere(ArbrePere_t ** arbre, ArbrePere_t * prec, char c);
void copieArbre(Noeud_t * arbre, ArbrePere_t ** arbrePere, int nbExp);
void AffichageArbrePere(ArbrePere_t * arbre);
void LibererArbrePere(ArbrePere_t ** arbre);

#endif