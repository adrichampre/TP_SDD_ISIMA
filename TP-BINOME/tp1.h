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


void global(char argv[], int *k);
int ** chargement(char nomFichier[], int * m, int * n);
void afficherMatrice(int ** mat, int m, int n);
void libererMatrice(int **mat, int m);
Liste insererEnTete(Liste l, int periode, int coutProd, int numero);
Liste insererEnFin(Liste l, int periode, int coutProd, int numero);
Liste nouvelleListe(void);
Liste convertirMatrice(int **mat, int m, int n, int k);
void libererListe(Liste l);
Liste supprUsine(Liste l, int u, int m);
Liste supprElt(maillon *prec, maillon *suppr);
void afficherListe(Liste l);
Liste supprPremierElt(Liste l);
void libererElt(maillon *m);
void sauvegarde(char *nomFichier, Liste l, int n);
int minimumTab(int **mat, int m, int n, int min);
void triTab(Usine *tab, int **mat, int m, int n); 
