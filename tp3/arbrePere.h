/* -------------------------------------------------------------------- */
/* 						Fichier d'entête arbrePere    					*/
/*                                                             			*/
/* Contient les prototypes des fonctions de traitement des arbres dont	*/
/* les noeuds contiennent un lien vers le pere. Egalement nous avons la */
/* structure qui définit un noeud d'arbre pere							*/
/*																		*/
/* -------------------------------------------------------------------- */

#ifndef ARBRE_PERE
#define ARBRE_PERE

#include "arbre.h"


/* ------------------------------------ */
/* 			Structure d'un noeud   		*/
/* ------------------------------------ */
typedef struct arbrePere
{
	char c;
	struct arbrePere * vertical;
	struct arbrePere * horizontal;
	struct arbrePere * pere;
}ArbrePere_t;

/* -------------------------------- */
/* 			Prototypes   			*/
/* -------------------------------- */

void InitArbrePere(ArbrePere_t ** arbre, ArbrePere_t * prec, char c);
void CopieArbre(Noeud_t * arbre, ArbrePere_t ** arbrePere, int nbExp);
void AffichageArbrePere(ArbrePere_t * arbre);
void LibererArbrePere(ArbrePere_t ** arbre);

#endif