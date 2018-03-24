#include "tp2.h"


void Global(void)//Regarder cours pour inversion des entiers, tests à faire avec code erreur
{
	pile_t * pile;
	file_t * file;
	elt_t e;
	int j;

	pile = InitPile(5);
	file = InitFile(5);
	Empiler(pile, 4);
	Empiler(pile, 2);
	Empiler(pile, 79);

	j = pile->nb_elt;
	for (int i = 0; i < j; ++i)
	{
		Depiler(pile, &e);
		printf("%d\n", e);
		Enfiler(file, e);
	}
	AfficherFile(file);
	printf("\n");
	j=file->nb_elmt;

	for (int i = 0; i < j; ++i)
	{
		Defiler(file, &e);
		printf("%d\n", e);
		Empiler(pile, e);
	}
	printf("\n");
	AfficherPile(pile);

	LibererFile(file);
	LibererPile(pile);
}