#include "arbre.h"
#include "pile.h"

int chargement(char *ligne, char *nomFichier)
{
	FILE *f;
	int Error=0;
	
	f=fopen(nomFichier,"r");
	if(!f)
	{
		printf("Problé d'ouverture de fichier !\n");
		Error = 2;
	}
	else
	{
		fgets(ligne, 50, f);
		fclose(f);
	}
	
	return Error;
}

Noeud * initNoeud()
{
		Noeud *n;
		
		n=(Noeud *)malloc(sizeof(Noeud));
		if(n!=NULL)
		{
			n->vertical=NULL;
			n->horizontal=NULL;
		}
		else
		{
			printf("Probleme d'allocation !\n");
		}
		return n;
}

Noeud * insertionVertical(Noeud *a, char c)
{
	Noeud *n=NULL;
	
	n=initNoeud();
	n->c=c;
	if(a!=NULL)
	{
		a->vertical=n;
	}
	else
	{
		a = n;
	}
	
	return n;
}

Noeud * insertionHorizontal(Noeud *a ,char c)
{
	Noeud *n=NULL;
	
	n=initNoeud();
	n->c=c;
	if(a!=NULL)
	{
		while(a->horizontal!=NULL)
		{
			a = a->horizontal;
		}
		a->horizontal=n;
	}
	
	return n;
}


Noeud * creerArbre(char *c)
{
	int i=0;
	pile_t *p;
	elt_t elt_p;
	Noeud *a=NULL;

	p=InitPile(strlen(c));

	while(c[i+1]!='\0')
	{
		switch(c[i])
		{
			case '(' :
			{
				a=insertionVertical(a, c[i+1]);
				elt_p.adr = a;
				elt_p.nb_fils=10;
				Empiler(p, elt_p);
				i++;
				
				break;
			}	
			case ',' :
			{
				a=insertionHorizontal(a, c[i+1]);
				i++;
				break;
			}
			case ')' :
			{
				Depiler(p,&elt_p);
				a = elt_p.adr;
				break;
			}
			default : 
				a=insertionHorizontal((p->val[p->nb_elt]).adr, c[i]);
				break;	
		}
		i++;
	}
	LibererPile(p);
	return a;
}



void LibererArbre(Noeud *a, int nbExp)
{
	elt_t cour;
	Noeud *n;
	pile_t *p;
	
	p=InitPile(nbExp);
	cour.adr=a;
	
	while(cour.adr!=NULL)
	{
		if((cour.adr)->vertical != NULL)
		{
			n = (cour.adr)->vertical;
			(cour.adr)->vertical = NULL;
			Empiler(p,cour);
			cour.adr = n;
		}
		else
		{
			if((cour.adr)->horizontal != NULL)
			{
				n = (cour.adr)->horizontal;
				(cour.adr)->horizontal = NULL;
				free(cour.adr);
				cour.adr = n;
			}
			else
			{
				free(cour.adr);
				if(Vide_Pile(p) == 0)
				{
					Depiler(p,&cour);
				}
				else
				{
					cour.adr=NULL;
				}
			}
		}
	}
	LibererPile(p);
}
