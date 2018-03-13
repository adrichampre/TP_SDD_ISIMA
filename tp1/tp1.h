/* -------------------------------------------------------------------- */
/* 		           		Fichier d'entête du tp1		                    */
/*                                                                      */
/* -------------------------------------------------------------------- */


#include "liste.h"

/* ---------------------------------------------------------- */
/*							Prototypes 					      */
/* ---------------------------------------------------------- */

void TriTab(usine_t * tab, int ** mat, int m, int n); 
int ** Chargement(char nomFichier[], int * m, int * n);
void AfficherMatrice(int ** mat, int m, int n);
void LibererMatrice(int ** mat, int m);
liste_t ConvertirMatrice(int ** mat, int m, int n, int k);
liste_t SupprUsine(liste_t l, int u);
void Sauvegarde(char * nomFichier, liste_t l);
void Global(char argv[], int * k);