#include "pile.h"


int PLEINE(pile_t *p)
{
	return (p->taille == p->indice);
}

int VIDE(pile_t *p)
{
	return (p->indice == -1);
}



int EMPILER(pile_t *p, elt_t val)
{
	int res=0;

	if(!PLEINE(p))
	{
		p->indice++;
		p->val[indice] = val;
	}
	else
	{
		printf("\nLa pile est pleine !\n");
		res = 1;
	}

	return res;
}

elt DEPILER(pile_t *p)
{
	if(!VIDE(p))
	{

	}
}

