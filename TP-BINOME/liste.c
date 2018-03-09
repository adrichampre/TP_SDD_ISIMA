#include "liste.h"

Liste insererEnTete(Liste l, int periode, int coutProd, int numero)
{
	maillon *m;
	
	m = (maillon *)malloc(sizeof(maillon));
	
	if(m == NULL)
	{
		printf("Erreur : Probleme d'allocation\n");
		exit(2);
	}

	m->u.periode = periode;
	m->u.coutProd = coutProd;
	m->u.numero = numero;
	
	m->suiv = l;

	return m;
}

Liste insererEnFin(Liste l, int periode, int coutProd, int numero)
{
	maillon *m,*a;

	
	m = (maillon *)malloc(sizeof(maillon));
	if(m == NULL)
	{
		printf("Erreur : Probleme d'allocation\n");
		exit(2);
	}

	m->suiv = nouvelleListe();
	

	m->u.periode = periode;
	m->u.coutProd = coutProd;
	m->u.numero = numero;

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
}

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
		libererElt(m);
		l = l->suiv;
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
	printf("----------------------------------------\n");
	printf("| Usine | periode | cout de production |\n");
	printf("|--------------------------------------|\n");
	
	while(l!=NULL)
	{
		printf("|   %d\t|    %d\t  |\t    %d\t       |\n",l->u.numero, l->u.periode, l->u.coutProd);
		l=l->suiv;
		if(l==NULL) printf("----------------------------------------\n");	
		else printf("|--------------------------------------|\n");
	}
}