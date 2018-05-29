/* -------------------------------------------------------------------- */
/*            Fichier contenant la fonction pour inverser 				*/
/*						les entiers d'une pile                   		*/
/*                                                                      */
/* -------------------------------------------------------------------- */

#include "tp2.h"


int InverseEntierPile(pile_t * pile, file_t * file)
{
	elt_t e;
	int j, err;

	j = pile->nb_elt;
	for (int i = 0; i < j; ++i)
	{
			err = Depiler(pile, &e);
			if(err == 1)
			{
				err = Enfiler(file, e);
			}
	}
	if(err == 1)
	{
		j=file->nb_elmt;
		for (int i = 0; i < j; ++i)
		{
			if(err == 1)
			{
				err = Defiler(file, &e);
				if(err == 1)
				{
					err = Empiler(pile, e);
				}
			}
		}
	}
	return err;
}