#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Usine
{
	int periode;
	int coutProd;
	int numero;
}Usine;

typedef struct maillon
{
	Usine u;
	struct maillon * suiv;
}maillon, *Liste;


Liste nouvelleListe(void);
Liste insererEnTete(Liste l, int periode, int coutProd, int numero);
Liste insererEnFin(Liste l, int periode, int coutProd, int numero);

void libererListe(Liste l);
void afficherListe(Liste l);
void libererElt(maillon *m);
Liste supprElt(maillon *prec, maillon *suppr);
Liste supprPremierElt(Liste l);