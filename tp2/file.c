/* -------------------------------------------------------------------- */
/*            Fichier contenant les fonctions de file                   */
/*                                                                      */
/* -------------------------------------------------------------------- */

#include "file.h"


/* ------------------------------------------------------------------------ */
/* InitFile          Initialise une file de taille n                    	*/
/*                                                                      	*/
/* En entrée: n correspond à la taille de la file                       	*/
/*                                                                      	*/
/* En sortie: Le pointeur sur la structure file_t qui vient d'être créée	*/
/* ------------------------------------------------------------------------ */

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
		free(file);
		exit(1);
	}
	file->tete = file->base;
	file->fin = file->base + file->taille - 1;

	return file;
}

/* -------------------------------------------------------------------- */
/* Vide_File          Permet d'indiquer si une file est vide            */
/*                                                                      */
/* En entrée: pointeur sur la structure file_t                          */
/*                                                                      */
/* En sortie: Un entier : 1 si elle est vide 							*/
/*						  0 si elle n'est pas vide        				*/
/* -------------------------------------------------------------------- */

int Vide_File(file_t * file)
{
	return (file->nb_elmt == 0);
}

/* ------------------------------------------------------------------------ */
/* Pleine_File          Permet d'indiquer si une file est pleine            */
/*                                                                      	*/
/* En entrée: pointeur sur la structure file_t                          	*/
/*                                                                      	*/
/* En sortie: Un entier : 1 si elle est pleine 								*/
/*						  0 si elle n'est pas pleine        				*/
/* ------------------------------------------------------------------------ */

int Pleine_File(file_t * file)
{
	return (file->nb_elmt == file->taille);
}

/* ------------------------------------------------------------------------ */
/* Enfiler          Permet d'enfiler un élément dans la file 	            */
/*                                                                      	*/
/* En entrée: file : pointeur sur la structure file_t                       */
/*			  e : élément à enfiler dans la file 							*/
/*                                                                      	*/
/* En sortie: erreur : le code d'erreur	: 1 aucune erreur 					*/
/*						  				  0 une erreur existe       		*/
/*					   file : pointeur de la structure file_t 				*/
/* ------------------------------------------------------------------------ */

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

/* ------------------------------------------------------------------------ */
/* Defiler          Permet de retirer un élément de la file 	            */
/*                                                                      	*/
/* En entrée: file : pointeur sur la structure file_t                       */
/*                                                                      	*/
/* En sortie: erreur : le code d'erreur	: 1 aucune erreur 					*/
/*						  				  0 une erreur existe       		*/
/*					   file : pointeur de la structure file_t 				*/
/*					   e : élément retirer de la file 						*/
/* ------------------------------------------------------------------------ */

int Defiler(file_t * file, elmt_t * e)
{
	int erreur;

	erreur = 1;
	if(!Vide_File(file))
	{
		*e = *(file->tete);
		file->tete = ((file->tete - file->base + 1)%file->taille) + file->base;
		file->nb_elmt--;
	}
	else
	{
		printf("La file est vide !\n");
		erreur = 0;
	}

	return erreur;
}

/* ------------------------------------------------------------------------ */
/* LibererFile          Permet de libérer la mémoire utilisée par la file   */
/*                                                                      	*/
/* En entrée: file : pointeur sur la structure file_t                       */
/*                                                                      	*/
/* ------------------------------------------------------------------------ */

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

/* ------------------------------------------------------------------------ */
/* AfficherFile          Permet d'afficher les éléments de la file 	        */
/*                                                                      	*/
/* En entrée: file : pointeur sur la structure file_t                       */
/*                                                                      	*/
/* ------------------------------------------------------------------------ */

void AfficherFile(file_t * file)
{
	printf("\nFile :\n");
	if(Vide_File(file))
	{
		printf("File vide !\n");
	}
	for (int i = 0; i < file->taille; ++i)
	{
		printf("%d\t", *(file->base + i));
	}
	printf("\n");
}