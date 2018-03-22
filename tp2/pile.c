#include "pile.h"


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

int Pleine_Pile(pile_t * p)
{
	return (p->taille == p->nb_elt);
}

int Vide_Pile(pile_t * p)
{
	return (p->nb_elt == 0);
}


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

int Depiler(pile_t * p, elt_t * val)
{
	int erreur = 1;
	if(!Vide_Pile(p))
	{
		* val = p->val[p->taille - p->nb_elt];
		p->nb_elt--;
 	}
	else
	{
		printf("\nLa pile est vide !\n");
		erreur = 0;
	}

	return erreur;
}

void LiberePile(pile_t * p)
{
	if(p != NULL)
	{
		free(p->val);
		free(p);
	}
}

void AfficherPile(pile_t * p)
{
	for (int i = p->nb_elt; i > 0; --i)
	{
		printf("%d\n", p->val[i]);
	}
}

