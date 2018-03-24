/* -------------------------------------------------------------------- */
/* 						Fichier d'entête pile    						*/
/*                                                             			*/
/* Contient les prototypes des fonctions de traitement d'une pile		*/
/* et la structure qui définit une pile et le type d'élément de la pile	*/
/*																		*/
/* -------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ------------------------------------ */
/* 		Type d'élément de la pile   	*/
/* ------------------------------------ */
typedef int elt_t;

/* ------------------------------------ */
/* 			Structure de la pile   		*/
/* ------------------------------------ */

typedef struct pile
{
	int taille;
	int nb_elt;
	elt_t *val;
}pile_t;

/* -------------------------------- */
/* 			Prototypes   			*/
/* -------------------------------- */

int Empiler(pile_t * p_pile, int val);
int Depiler(pile_t * p_pile, elt_t * e);
int Vide_Pile(pile_t * p);
int Pleine_Pile(pile_t * p);
void AfficherPile(pile_t * p);
pile_t * InitPile(int n);
void LibererPile(pile_t * p);