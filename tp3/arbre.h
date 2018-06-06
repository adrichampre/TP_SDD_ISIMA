#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

}Noeud;


Noeud * initNoeud();
Noeud * insertionVertical(Noeud *a, char c);
Noeud * insertionHorizontal(Noeud *a ,char c);
Noeud * creerArbre(char *c);
int chargement(char *ligne, char *nomFichier);
void LibererArbre(Noeud *a, int nbExp);
void AffichagePostFixe(Noeud *a, int nbExp);
int rechercher(Noeud *a, Noeud ** noeud, char c, int nbExp);
void InsertionFils(Noeud *a, char r, char v, int nbExp);

#endif
