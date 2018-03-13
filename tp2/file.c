#include "file.h"



file_t * InitFile(int n)
{
	file_t * file;

	file = (file_t *)malloc(sizeof(file_t));
	if(file == NULL)
	{
		printf("\nProbléme d'allocation avec la file !\n");
		exit(1);
	}
	file->taille = n;
	file->nb_elmt = 0;

	file->base = (elmt_t *)malloc(sizeof(elmt_t) * file->taille);
	if(file->base == NULL)
	{
		printf("\nProbléme d'allocation avec la file !\n");
		exit(1);
	}
	file->tete = file->base;
	file->fin = file->base + file->taille;

	return file;
}

int Vide(file_t * file)
{
	return (file->nb_elmt == 0);
}

int Plein(file_t * file)
{
	return (file->nb_elmt == file->taille);
}

/*int Enfiler(file_t * file, elmt_t e)//Quand tete arrive sur fin repasse au début
{
	int erreur = 0;
	if(!Plein(file))
	{

	}
}*/