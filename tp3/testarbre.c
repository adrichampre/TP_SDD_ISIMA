#include "arbrePere.h"
#include "autresFonctions.h"

int main()
{
	Noeud_t *a=NULL;
	ArbrePere_t *arbre;
	char ligne[50];
	int Error=0,nbExp;
	
	Error = Chargement(ligne,"text.txt");
	if(Error==0)
	{
		nbExp = strlen(ligne);
		a=CreerArbre(ligne);
		InsertionFils(a,'a','q',nbExp);
		AffichagePostFixe(a,nbExp);
		CopieArbre(a,&arbre,nbExp);
		AffichageArbrePere(arbre);
		LibererArbrePere(&arbre);
		LibererArbre(a,strlen(ligne));
	}
	

	return Error;
}
