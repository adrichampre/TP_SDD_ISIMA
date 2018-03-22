#include "tp2.h"


void Global(void)
{
	pile_t * pile;
	elt_t e;

	pile = InitPile(5);
	Empiler(pile, 4);
	Empiler(pile, 2);
	Depiler(pile, &e);
	Empiler(pile, 79);
	Empiler(pile, 14);
	Empiler(pile, 79);
	Empiler(pile, 14);
	Empiler(pile, 79);
	Empiler(pile, 14);
	Depiler(pile, &e);
	AfficherPile(pile);

	LiberePile(pile);
}