#include "arbre.h"

int main()
{
	Noeud *a=NULL;
	char ligne[50];
	int Error=0;
	Error = chargement(ligne,"text.txt");

	a=creerArbre(ligne);
	LibererArbre(a,strlen(ligne));
	
	return Error;
}
