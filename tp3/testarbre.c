#include "arbrePere.h"
#include "autresFonctions.h"

int main(int argc, char **argv)
{
	Noeud_t *a=NULL;
	ArbrePere_t *arbre;
	char ligne[50];
	int Error=0,nbExp=0;
	
	Error = Chargement(ligne,argv[1]);
	nbExp = strlen(ligne);
	if(Error==0 && nbExp > 2)
	{
		a=CreerArbre(ligne,nbExp);
		AffichagePostFixe(a,nbExp);

		InsertionFils(a,'b','N',nbExp);
		printf("\n");
		AffichagePostFixe(a,nbExp);
		CopieArbre(a,&arbre,nbExp);

		AffichageArbrePere(arbre);
		LibererArbrePere(&arbre);
		LibererArbre(a,strlen(ligne));
	}

	return Error;
}
