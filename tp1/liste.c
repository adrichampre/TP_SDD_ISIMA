#include "liste.h"

void afficherElt(Liste l)
{
	printf("Usien : %d Valeur :%d ",l->usine, l->periode);
}

Liste insererEnTete(Liste l, int val, int usine)//A finir !!!!!!
{
	maillon *m;
	int i;
	
	m = (maillon *)malloc(sizeof(maillon));
	if(m == NULL)
	{
		printf("Probleme d'allocation\n");
		exit(2);
	}

	m->periode = val;
	m->usine = usine;
	m->suiv = l;

	return m;
}

/*Liste insererEnFin(Liste l, int *periode, int n)
{
	maillon *m,*a;
	int i;

	
	m = (maillon *)malloc(sizeof(maillon));
	if(m == NULL)
	{
		printf("Probleme d'allocation\n");
		exit(2);
	}

	m->periode = (int *)malloc(sizeof(int)*n);
	if(m->periode == NULL)
	{
		printf("Probleme d'allocation\n");
		exit(2);
	}

	m->suiv = nouvelleListe();
	for(i=0;i<n;i++)
	{
		m->periode[i] = periode[i];	
	}

	if(l != NULL)
	{

		a=l;

		while(a->suiv != NULL)
		{
			a = a->suiv;
		}

		a->suiv = m;

	}
	else
	{
		l = m;
	}
		
	return l;
}*/


Liste nouvelleListe(void)
{
	return NULL;
}

void libererListe(Liste l)
{
	maillon *m;
	while(l!=NULL)
	{
		m = l;
		l = l->suiv;
		libererElt(m);
	}
}

void libererElt(maillon *m)
{
	free(m);
}

Liste supprPremierElt(Liste l)
{
	maillon *m;

	m=l;
	l=l->suiv;
	libererElt(m);

	return l;
}

Liste supprElt(maillon *prec, maillon *suppr)
{
	prec->suiv = suppr->suiv;
	libererElt(suppr);

	return prec;
}

void afficherListe(Liste l)
{
	int i;

	while(l!=NULL)
	{
		printf("%d ", l->periode);
		printf("\n");
		l=l->suiv;
	}
}