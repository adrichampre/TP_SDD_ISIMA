/* -------------------------------------------------------------------- */
/* 		           		Fichier d'entête du tp1		                    */
/*                                                                      */
/* -------------------------------------------------------------------- */


#include "liste.h"

void triTab(usine_t * tab, int ** mat, int m, int n); 
int ** chargement(char nomFichier[], int * m, int * n);
void afficherMatrice(int ** mat, int m, int n);
void libererMatrice(int ** mat, int m);
liste_t convertirMatrice(int ** mat, int m, int n, int k);
liste_t supprUsine(liste_t l, int u);
void sauvegarde(char * nomFichier, liste_t l);
void global(char argv[], int * k);