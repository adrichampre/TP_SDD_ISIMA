#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "noeud.h"


#ifndef ARBRE
#define ARBRE

typedef struct noeud
{
	char c;
	struct noeud *vertical;
	struct noeud *horizontal;

}Noeud, *Arbre;


Arbre initArbre();
Arbre insertionVertical(Arbre a, char c);
Arbre insertionHorizontal(Arbre a, char c);
Arbre lireChaine(Arbre a, char *c);
void chargement(char *ligne, FILE *f);	

#endif
