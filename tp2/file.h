#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elmt_t;

typedef struct file_t
{
	int taille;
	int nb_elmt;
	elmt_t * tete;
	elmt_t * fin;
	elmt_t * base;
}file_t;


file_t * InitFile(int n);
int Vide_File(file_t * file);
int Pleine_File(file_t * file);
int Enfiler(file_t * file, elmt_t e);
int Defiler(file_t * file, elmt_t * e);
void LibererFile(file_t * file);
void AfficherFile(file_t * file);