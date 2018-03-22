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
	file->fin = file->base + file->taille - 1;

	return file;
}

int Vide_File(file_t * file)
{
	return (file->nb_elmt == 0);
}

int Pleine_File(file_t * file)
{
	return (file->nb_elmt == file->taille);
}

int Enfiler(file_t * file, elmt_t e)
{
	int erreur = 1;
	if(!Pleine_File(file))
	{
		file->fin = ((file->fin - file->base + 1)%file->taille) + file->base;
		*(file->fin) = e;
		file->nb_elmt++;
	}
	else
	{
		printf("File pleine !\n");
		erreur = 0;
	}

	return erreur;
}

int Defiler(file_t * file, elmt_t * e)
{
	int erreur;

	erreur = 1;
	if(!Vide_File(file))
	{
		e = file->tete;
		file->tete = ((file->tete - file->base + 1)%file->taille) + file->base;
		file->nb_elmt--;
	}
	else
	{
		erreur = 0;
	}

	return erreur;
}

void LibererFile(file_t * file)
{
	if(file != NULL)
	{
		if(file->base != NULL)
		{
			free(file->base);
		}
		free(file);
	}
}

void AfficherFile(file_t * file)
{
	printf("\n");
	if(file->nb_elmt == 0)
	{
		printf("File vide !\n");
	}
	for (int i = 0; i < file->taille; ++i)
	{
		printf("%d\t", *(file->base + i));
	}
	printf("\n");
}