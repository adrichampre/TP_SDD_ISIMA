#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct maillon
{
	int periode;
	int usine;
	struct maillon * suiv;
}maillon, *Liste;


void global(char argv[],int k);
int ** chargement(char nomFichier[], int * m, int * n);
void afficherMatrice(int ** mat, int m, int n);
void libererMatrice(int **mat, int m);
Liste convertirMatrice(int **mat, int m, int n, int k);
Liste supprUsine(Liste l, int u, int m);
void sauvegarde(char *nomFichier, Liste l);
int minimumTab(int **mat, int m, int n, int min, int *usine);

void afficherElt(Liste l);
Liste insererEnTete(Liste l, int val, int usine);
Liste nouvelleListe(void);
void libererListe(Liste l);
Liste insererEnFin(Liste l, int *periode, int n);
Liste supprElt(maillon *prec, maillon *suppr);
void afficherListe(Liste l);
Liste supprPremierElt(Liste l);
void libererElt(maillon *m);