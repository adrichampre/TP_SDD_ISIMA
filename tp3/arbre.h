#include "noeud.h"
#include "pile.h"
#include "file.h"


#ifndef ARBRE
#define ARBRE

typedef struct noeud
{
	char c;
	struct noeud *vertical;
	struct noeud *horizontal;

}Noeud_t;


Noeud_t * initNoeud();
Noeud_t * insertionVertical(Noeud_t *a, char c);
Noeud_t * insertionHorizontal(Noeud_t *a ,char c);
Noeud_t * creerArbre(char *c);
void LibererArbre(Noeud_t *a, int nbExp);
void AffichagePostFixe(Noeud_t *a, int nbExp);
int rechercher(Noeud_t *a, Noeud_t ** noeud, char c, int nbExp);
void InsertionFils(Noeud_t *a, char r, char v, int nbExp);

#endif
