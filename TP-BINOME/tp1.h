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

Liste convertirMatrice(int **mat, int m, int n, int k);

Liste supprUsine(Liste l, int u, int m);

void sauvegarde(char *nomFichier, Liste l, int n);

void triTab(Usine *tab, int **mat, int m, int n); 
