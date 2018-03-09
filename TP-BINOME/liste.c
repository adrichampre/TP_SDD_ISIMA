#include "liste.h"

liste_t insererEnTete(liste_t l, int periode, int coutProd, int numero)
{
	maillon_t * m;
	
	m = (maillon_t *)malloc(sizeof(maillon_t));
	
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

liste_t insererEnFin(liste_t l, int periode, int coutProd, int numero)
{
	maillon_t * m,* a;

	
	m = (maillon_t *)malloc(sizeof(maillon_t));
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

liste_t nouvelleListe(void)
{
	return NULL;
}

void libererListe(liste_t l)
{
	maillon_t * m;

	while(l!=NULL)
	{
		m = l;
		libererElt(m);
		l = l->suiv;
	}
}

void libererElt(maillon_t * m)
{
	free(m);
}

liste_t supprPremierElt(liste_t l)
{
	maillon_t * m;

	if (l != NULL)
	{
		m=l;
		l=l->suiv;
		libererElt(m);
	}
	else
	{
		l = NULL;
	}
	return l;
}

liste_t supprElt(maillon_t * prec, maillon_t *suppr)
{
	prec->suiv = suppr->suiv;
	libererElt(suppr);

	return prec;
}

void afficherListe(liste_t l)
{	
	printf("----------------------------------------\n");
	printf("| Usine | periode | cout de production |\n");
	printf("|--------------------------------------|\n");
	
	while(l!=NULL)
	{
		printf("|   %d\t|    %d\t  |\t    %d\t       |\n",l->u.numero, l->u.periode, l->u.coutProd);
		if(l->suiv==NULL) printf("----------------------------------------\n");	
		else printf("|--------------------------------------|\n");
		l=l->suiv;
	}
}