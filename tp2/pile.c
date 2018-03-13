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
		exit(1);
	}

	return p;
}

int Pleine(pile_t * p)
{
	return (p->taille == p->nb_elt);
}

int Vide(pile_t * p)
{
	return (p->nb_elt == -1);
}


int Empiler(pile_t * p, elt_t val)
{
	int res=0;

	if(!Pleine(p))
	{
		p->nb_elt++;
		p->val[p->nb_elt] = val;
	}
	else
	{
		printf("\nLa pile est pleine !\n");
		res = 1;
	}

	return res;
}

int Depiler(pile_t * p, elt_t * val)
{
	int erreur = 0;
	if(!Vide(p))
	{
		* val = p->val[p->taille - p->nb_elt];
		p->nb_elt--;
 	}
	else
	{
		printf("\nLa pile est vide !\n");
		erreur = 1;
	}

	return erreur;
}

void AfficherPile(pile_t * p)
{
	for (int i = p->nb_elt; i < p->taille; ++i)
	{
		printf("%d\n", p->val[i]);
	}
}

