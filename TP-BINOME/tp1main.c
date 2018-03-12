/* -------------------------------------------------------------------- */
/*            		Fichier avec simplement le main                 	*/
/*                                                                      */
/* -------------------------------------------------------------------- */


#include "tp1.h"

/* -------------------------------------------------------------------- */
/* main          				Fonction main    						*/
/*                                                             			*/
/* En entrée: argc nombre d'arguments									*/
/*			  argv tableau de chaîne de caractéres des arguments		*/
/*																		*/
/* En sortie: le code de retour  										*/
/* -------------------------------------------------------------------- */


int main(int argc, char ** argv)
{
	int k;
	
	if(argc<2 || argc>3)
	{
		printf("Erreur : il faut 1 argument minimum et 2 arguments maximum\n");
		exit(1);
	}
	if(argc==2)
	{
		k=0;
	}
	else k = atoi(argv[2]);
	Global(argv[1], &k);
	return 0;
}
