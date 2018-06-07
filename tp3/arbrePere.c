/* -------------------------------------------------------------------- */
/*            Fichier contenant les fonctions de l'arbre pere           */
/*                                                                      */
/* -------------------------------------------------------------------- */

#include "arbrePere.h"

/* ------------------------------------------------------------------------ */
/* InitArbrePere          Initialise un arbre pere 		                    */
/*                                                                      	*/
/* En entrée: arbre pointeur de pointeur sur l'arbre créé                  	*/
/*			  prec pointeur sur le noeud précédent le nouveau à créer		*/
/*			  c caractére à insérer dans le nouveau noeud 					*/
/*                                                                      	*/
/* En sortie: arbre 														*/
/* ------------------------------------------------------------------------ */
void InitArbrePere(ArbrePere_t ** arbre, ArbrePere_t * prec, char c)
{
	(*arbre) = (ArbrePere_t *)malloc(sizeof(ArbrePere_t));
	if(*arbre != NULL)
	{
		(*arbre)->c = c;
		(*arbre)->horizontal = NULL ;
		(*arbre)->vertical = NULL ;
		(*arbre)->pere = prec;
	}
	else
	{
		printf("Probleme d'allocation\n");
	}
}

void CopieArbre(Noeud_t * arbre, ArbrePere_t ** arbrePere, int nbExp)
{
	elt_t eltPile;
	pile_t * p;
	ArbrePere_t *cour=(*arbrePere), *prec=NULL;
	ArbrePere_t **precArbre = arbrePere;
	eltPile.adr = arbre;

	p=InitPile(nbExp);

	while(eltPile.adr != NULL)
	{

		InitArbrePere(precArbre, prec, (eltPile.adr)->c);
		cour = *precArbre;
		if((eltPile.adr)->vertical != NULL)
		{
			precArbre = &(cour->vertical);
			prec = cour;
			Empiler(p,eltPile);
			eltPile.adr = (eltPile.adr)->vertical;
		}
		else
		{
			if((eltPile.adr)->horizontal != NULL)
			{
				eltPile.adr = (eltPile.adr)->horizontal;
				precArbre = &(cour->horizontal);
			}
			else
			{
				while(eltPile.adr != NULL && (eltPile.adr)->horizontal == NULL)
				{
					if(!Vide_Pile(p))
					{
						Depiler(p,&eltPile);
						cour = cour->pere;
						prec = prec->pere;
					}
					else
					{
						eltPile.adr = NULL;
					}
				}
				if(eltPile.adr != NULL)
				{
					eltPile.adr = (eltPile.adr)->horizontal;
					precArbre = &(cour->horizontal);
				}
			}
		}
	}
	LibererPile(p);
}


void AffichageArbrePere(ArbrePere_t * arbre)
{
	ArbrePere_t * cour = arbre;

	while(cour != NULL)
	{
		if(cour->vertical != NULL)
		{
			cour = cour->vertical;
		}
		else
		{
			printf("%c\n", cour->c);
			if(cour->horizontal != NULL)
			{
				cour = cour->horizontal;
			}
			else
			{
				while(cour != NULL && cour->horizontal == NULL)
				{
					if(cour->pere != NULL)
					{
						cour = cour->pere;
						printf("%c\n", cour->c);
					}
					else
					{
						cour = NULL;
					}
				}
				if(cour != NULL)
				{
					cour = cour->horizontal;
				}
			}
		}
	}
}


void LibererArbrePere(ArbrePere_t ** arbre)
{
	ArbrePere_t * cour = *arbre;
	ArbrePere_t * suiv = NULL;

	while(cour != NULL)
	{
		if(cour->vertical != NULL)
		{
			suiv = cour->vertical;
			cour->vertical = NULL;
			cour=suiv;
		}
		else
		{
			if(cour->horizontal != NULL)
			{
				suiv = cour->horizontal;
				cour->horizontal = NULL;
				free(cour);
				cour = suiv;
			}
			else
			{
				suiv = cour->pere;
				free(cour);
				if(suiv != NULL)
				{
					cour = suiv;
				}
				else
				{
					cour = NULL;
				}
			}
		}
	}
}