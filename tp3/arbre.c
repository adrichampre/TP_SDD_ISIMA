#include "arbre.h"
#include "pile.h"

void chargement(char *ligne, FILE *f)
{
	
}

Arbre initArbre()
{
		Noeud *n;
		
		n=(Noeud *)malloc(sizeof(Noeud));
		n->vertical=NULL;
		n->horizontal=NULL;
		
		return n;
}

Arbre insertionVertical(Arbre a, char c)
{
	Noeud *n;
	
	n=initArbre();
	if(a==NULL)
	{
		n->c=c;
		n->vertical=NULL;
		n->horizontal=NULL;
	}
	else
	{
		n->c=c;
		n->vertical=NULL;
		n->horizontal=NULL;
		a->vertical=n;
	}
	
	return n;
}

Arbre insertionHorizontal(Arbre a, char c)
{
	Noeud *n;
	
	n=initArbre();
	n->c=c;
	n->vertical=NULL;
	n->horizontal=NULL;
	a->horizontal=n;
	
	return n;
}


Arbre lireChaine(Arbre a, char *c)
{
	int i;
	i=0;
	pile_t *pile;
	elt_t eltp;
	pile=InitPile(20);
	while(c[i]!='\0')
	{
		switch(c[i])
		{
			case '(' :
			{
				a=insertionVertical(a, c[i+1]);
				eltp.adr = a;
				eltp.nb_fils = 0;
				Empiler(pile, eltp); 
			}	
			case ',' :
				a=insertionHorizontal(a, c[i+1]);
			case ')' :
			{
				Depiler(pile,NULL);
				while(a->horizontal!=NULL)
				{
					a=a->horizontal;
				}
				a=insertionHorizontal((pile->val)->adr, c[i+1]);
			}
			default : 
				break;	
		}
		i++;
	}
	LibererPile(pile);
}
