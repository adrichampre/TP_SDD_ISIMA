#include "arbrePere.h"
#include "autresFonctions.h"

int main()
{
	Noeud_t *a=NULL;
	ArbrePere_t *arbre;
	char ligne[50];
	int Error=0,nbExp;
	
	Error = chargement(ligne,"text.txt");
	nbExp = strlen(ligne);
	a=creerArbre(ligne);
	InsertionFils(a,'a','q',nbExp);
	AffichagePostFixe(a,nbExp);
	copieArbre(a,&arbre,nbExp);
	AffichageArbrePere(arbre);
	LibererArbrePere(&arbre);
	LibererArbre(a,strlen(ligne));

	return Error;
}
