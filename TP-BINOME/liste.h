/* -------------------------------------------------------------------- */
/* 						Fichier d'entête liste    						*/
/*                                                             			*/
/* Contient les prototypes des fonctions de traitement de liste			*/
/* et les structures qui définissent une usine et la liste chaînée		*/
/*																		*/
/* -------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ---------------------------------------------------------- */
/*					Structure d'une usine 					  */
/* ---------------------------------------------------------- */

typedef struct usine_t
{
	int periode;
	int coutProd;
	int numero;
}usine_t;

/* ---------------------------------------------------------- */
/*				Structure de la liste chaînée 				  */
/* ---------------------------------------------------------- */

typedef struct maillon_t
{
	usine_t u;
	struct maillon_t * suiv;
}maillon_t, * liste_t;


/* ---------------------------------------------------------- */
/*							Prototypes					      */
/* ---------------------------------------------------------- */


liste_t NouvelleListe(void);
liste_t InsererEnTete(liste_t l, usine_t u);
liste_t InsererEnFin(liste_t l, usine_t u);

void LibererListe(liste_t l);
void AfficherListe(liste_t l);
void LibererElt(maillon_t * m);
liste_t SupprElt(maillon_t * prec, maillon_t *suppr);
liste_t SupprPremierElt(liste_t l);