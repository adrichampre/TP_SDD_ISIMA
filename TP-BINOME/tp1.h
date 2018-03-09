#include "liste.h"

void triTab(Usine *tab, int **mat, int m, int n); 

int ** chargement(char nomFichier[], int * m, int * n);

void afficherMatrice(int ** mat, int m, int n);
void libererMatrice(int **mat, int m);

Liste convertirMatrice(int **mat, int m, int n, int k);

Liste supprUsine(Liste l, int u);

void sauvegarde(char *nomFichier, Liste l);


void global(char argv[], int *k);