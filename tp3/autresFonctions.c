#include "autresFonctions.h"

/* ------------------------------------------------------------------------------------ */
/* Chargement          			Charge le fichier 		                    			*/
/*                                                                      				*/
/* En entrée: nomFichier chaîne de caractéres correspondant au chemin du fichier		*/
/*                                                                      				*/
/* En sortie: ligne chaîne de caractéres à renvoyer 									*/
/* ------------------------------------------------------------------------------------ */

int Chargement(char *ligne, char *nomFichier)
{
	FILE *f;
	int Error=0;
	
	f=fopen(nomFichier,"r");
	if(!f)
	{
		printf("Probléme d'ouverture de fichier !\n");
		Error = 2;
	}
	else
	{
		fgets(ligne, 50, f);
		fclose(f);
	}
	
	return Error;
}