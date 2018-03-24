/* -------------------------------------------------------------------- */
/*            Fichier contenant les fonctions de pile                   */
/*                                                                      */
/* -------------------------------------------------------------------- */

#include "pile.h"

/* ------------------------------------------------------------------------ */
/* InitFile          Initialise une pile de taille n                    	*/
/*                                                                      	*/
/* En entrée: n correspond à la taille de la pile                       	*/
/*                                                                      	*/
/* En sortie: Le pointeur sur la structure pile_t qui vient d'être créée	*/
/* ------------------------------------------------------------------------ */

pile_t * InitPile(int n)
{
	pile_t * p;

	p = (pile_t *)malloc(sizeof(pile_t));
	if(p == NULL)
	{
		printf("Probléme d'allocation pour la pile !\n");
		exit(1);
	}
	p->taille = n;
	p->nb_elt = 0;

	p->val = (elt_t *)malloc(sizeof(elt_t) * p->taille);
	if(p->val == NULL)
	{
		printf("Probléme d'allocation pour le tableau des valeurs !\n");
		free(p);
		p=NULL;
		exit(1);
	}

	return p;
}


/* ------------------------------------------------------------------------ */
/* Pleine_Pile          Permet d'indiquer si une pile est pleine            */
/*                                                                      	*/
/* En entrée: pointeur sur la structure pile_t                          	*/
/*                                                                      	*/
/* En sortie: Un entier : 1 si elle est pleine 								*/
/*						  0 si elle n'est pas pleine        				*/
/* ------------------------------------------------------------------------ */

int Pleine_Pile(pile_t * p)
{
	return (p->taille == p->nb_elt);
}

/* -------------------------------------------------------------------- */
/* Vide_Pile          Permet d'indiquer si une pile est vide            */
/*                                                                      */
/* En entrée: pointeur sur la structure pile_t                          */
/*                                                                      */
/* En sortie: Un entier : 1 si elle est vide 							*/
/*						  0 si elle n'est pas vide        				*/
/* -------------------------------------------------------------------- */

int Vide_Pile(pile_t * p)
{
	return (p->nb_elt == 0);
}

/* ------------------------------------------------------------------------ */
/* Empiler          Permet d'empiler un élément dans la pile 	            */
/*                                                                      	*/
/* En entrée: p : pointeur sur la structure pile_t                       	*/
/*			  val : élément à empiler dans la pile 							*/
/*                                                                      	*/
/* En sortie: erreur : le code d'erreur	: 1 aucune erreur 					*/
/*						  				  0 une erreur existe       		*/
/*					   p : pointeur de la structure pile_t 					*/
/* ------------------------------------------------------------------------ */

int Empiler(pile_t * p, elt_t val)
{
	int erreur=1;

	if(!Pleine_Pile(p))
	{
		p->nb_elt++;
		p->val[p->nb_elt] = val;
	}
	else
	{
		printf("\nLa pile est pleine !\n");
		erreur = 0;
	}

	return erreur;
}

/* ------------------------------------------------------------------------ */
/* Depiler          Permet de retirer un élément de la pile 	            */
/*                                                                      	*/
/* En entrée: p : pointeur sur la structure pile_t                       	*/
/*                                                                      	*/
/* En sortie: erreur : le code d'erreur	: 1 aucune erreur 					*/
/*						  				  0 une erreur existe       		*/
/*					   p : pointeur de la structure pile_t 					*/
/*					   val : élément retirer de la pile 					*/
/* ------------------------------------------------------------------------ */

int Depiler(pile_t * p, elt_t * val)
{
	int erreur = 1;
	if(!Vide_Pile(p))
	{
		* val = p->val[p->nb_elt];
		p->nb_elt--;
 	}
	else
	{
		printf("\nLa pile est vide !\n");
		erreur = 0;
	}

	return erreur;
}


/* ------------------------------------------------------------------------ */
/* LibererPile          Permet de libérer la mémoire utilisée par la pile   */
/*                                                                      	*/
/* En entrée: p : pointeur sur la structure pile_t                       	*/
/*                                                                      	*/
/* ------------------------------------------------------------------------ */

void LibererPile(pile_t * p)
{
	if(p != NULL)
	{
		free(p->val);
		free(p);
	}
}

/* ------------------------------------------------------------------------ */
/* AfficherPile          Permet d'afficher les éléments de la pile 	        */
/*                                                                      	*/
/* En entrée: p : pointeur sur la structure pile_t                       	*/
/*                                                                      	*/
/* ------------------------------------------------------------------------ */

void AfficherPile(pile_t * p)
{
	for (int i = p->nb_elt; i > 0; --i)
	{
		printf("%d\n", p->val[i]);
	}
}

