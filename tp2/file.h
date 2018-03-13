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
int Vide(file_t * file);
int Plein(file_t * file);