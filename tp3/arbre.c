#include "arbre.h"

Noeud_t * initNoeud()
{
		Noeud_t *n;
		
		n=(Noeud_t *)malloc(sizeof(Noeud_t));
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

Noeud_t * insertionVertical(Noeud_t *a, char c)
{
	Noeud_t *n=NULL;
	
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

Noeud_t * insertionHorizontal(Noeud_t *a ,char c)
{
	Noeud_t *n=NULL;
	
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


Noeud_t * creerArbre(char *c)
{
	int i=0;
	pile_t *p;
	elt_t elt_p;
	Noeud_t *a=NULL;

	p=InitPile(strlen(c));

	while(c[i+1]!='\0')
	{
		switch(c[i])
		{
			case '(' :
			{
				a=insertionVertical(a, c[i+1]);
				elt_p.adr = a;
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

void AffichagePostFixe(Noeud_t *a, int nbExp)
{
	elt_t cour,prec;
	pile_t *p;
	
	p=InitPile(nbExp);
	cour.adr=a;

	while(cour.adr!=NULL)
	{
		if((cour.adr)->vertical != NULL)
		{
			cour.nb_fils = 1;
			Empiler(p,cour);
			cour.adr = (cour.adr)->vertical;
		}
		else
		{
			cour.nb_fils = 0;
			printf("%c --> %d\n", (cour.adr)->c, cour.nb_fils);
			if((cour.adr)->horizontal != NULL)
			{
				if(!Vide_Pile(p))
				{
					Depiler(p,&prec);
					prec.nb_fils++;
					Empiler(p,prec);
				}
				cour.adr = (cour.adr)->horizontal;
			}
			else
			{
				while(cour.adr != NULL && (cour.adr)->horizontal == NULL)
				{
					if(!Vide_Pile(p))
					{
						Depiler(p,&cour);
						printf("%c --> %d\n", (cour.adr)->c, cour.nb_fils);
					}
					else
					{
						cour.adr=NULL;
					}
				}
				if(cour.adr != NULL)
				{
					cour.adr = cour.adr->horizontal;
					if(!Vide_Pile(p))
					{
						Depiler(p,&prec);
						prec.nb_fils++;
						Empiler(p,prec);
					}
				}
			}
		}
	}
	LibererPile(p);
}


int rechercher(Noeud_t *a, Noeud_t ** noeud, char c, int nbExp)
{
	Noeud_t * cour = a;	
	file_t *f;
	int erreur=1;

	cour=a;
	f=InitFile(nbExp);
	Enfiler(f,cour);
	while(cour != NULL && cour->c != c)
	{	
		if(cour->vertical != NULL)
		{
			erreur = Enfiler(f,cour);
		}
		if(cour->horizontal != NULL)
		{		
			cour=cour->horizontal;															
		}	
		else
		{
			if(!Vide_File(f))
			{
				erreur = Defiler(f,&cour);
				cour=cour->vertical;
			}
			else
			{
				cour = NULL;
			}
		}		
	}
	if(cour != NULL)
	{
		*noeud = cour;
	}
	else
	{
		*noeud = NULL;
		erreur = 0;
	}
	LibererFile(f);

	return erreur;
}


void InsertionFils(Noeud_t *a, char r, char v, int nbExp)
{
	Noeud_t *cour,*prec;
	Noeud_t **noeud;

	if(rechercher(a,&cour,r,nbExp))
	{
		prec = cour;
		noeud = &(cour->vertical);
		if(cour->vertical != NULL)
		{
			cour = cour->vertical;
			while(cour != NULL && cour->c < v)
			{
				noeud = &((*noeud)->horizontal);
				cour = cour->horizontal;
			}
		}
		*noeud = initNoeud();
		if(noeud != NULL)
		{
			(*noeud)->c = v;
			if(cour != prec)
			{
				(*noeud)->horizontal = cour;
			}
		}
	}
}


void LibererArbre(Noeud_t *a, int nbExp)
{
	elt_t cour;
	Noeud_t *n;
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
