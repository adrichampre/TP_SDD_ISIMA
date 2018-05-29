#include "tp2.h"

int main(void)
{
	pile_t * pile;
	file_t * file;
	int err, n=3;

	pile = InitPile(2);
	file = InitFile(n);
	//Empiler(pile, 4);
	Empiler(pile, 2);
	err = Empiler(pile, 79);
	AfficherPile(pile);
	if(err == 1)
	{
		err = InverseEntierPile(pile, file);
	}
	printf("\n");
	AfficherPile(pile);
	LibererFile(file);
	LibererPile(pile);

	return err;
}