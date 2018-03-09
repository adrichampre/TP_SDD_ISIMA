#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct usine_t
{
	int periode;
	int coutProd;
	int numero;
}usine_t;

typedef struct maillon_t
{
	usine_t u;
	struct maillon_t * suiv;
}maillon_t, * liste_t;


liste_t nouvelleListe(void);
liste_t insererEnTete(liste_t l, int periode, int coutProd, int numero);
liste_t insererEnFin(liste_t l, int periode, int coutProd, int numero);

void libererListe(liste_t l);
void afficherListe(liste_t l);
void libererElt(maillon_t * m);
liste_t supprElt(maillon_t * prec, maillon_t *suppr);
liste_t supprPremierElt(liste_t l);