#include "arbre.h"

int main()
{
	Noeud *a=NULL;
	Noeud * noeud;
	char ligne[50];
	int Error=0,nbExp;
	
	Error = chargement(ligne,"text.txt");
	nbExp = strlen(ligne);
	a=creerArbre(ligne);
InsertionFils(a,'a','q',nbExp);
	AffichagePostFixe(a,nbExp);
	
	LibererArbre(a,strlen(ligne));

	return Error;
}
