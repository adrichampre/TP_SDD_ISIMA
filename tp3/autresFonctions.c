#include "autresFonctions.h"

int chargement(char *ligne, char *nomFichier)
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