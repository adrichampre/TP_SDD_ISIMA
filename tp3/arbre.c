/* -------------------------------------------------------------------- */
/*            Fichier contenant les fonctions de l'arbre 	            */
/*                                                                      */
/* -------------------------------------------------------------------- */

#include "arbre.h"


/* ------------------------------------------------------------------------ */
/* InitNoeud   		       Initialise un noeud 		 	                    */
/*                                                                      	*/
/* En entrée: 											                  	*/
/*                                                                      	*/
/* En sortie: Nouveau noeud													*/
/* ------------------------------------------------------------------------ */
Noeud_t * InitNoeud()
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

/* ------------------------------------------------------------------------ */
/* InsertionVertical          Insére un lien vertical 	                    */
/*                                                                      	*/
/* En entrée: a pointeur sur le noeud à ajouter un lien 					*/
/*			  c caractére à insérer dans le nouveau noeud 					*/
/*                                                                      	*/
/* En sortie: adresse du nouveau noeud inséré								*/
/* ------------------------------------------------------------------------ */
Noeud_t * InsertionVertical(Noeud_t *a, char c)
{
	Noeud_t *n=NULL;
	
	n=InitNoeud();
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

/* ------------------------------------------------------------------------ */
/* InsertionHorizontal          Insére un lien horizontal 	                */
/*                                                                      	*/
/* En entrée: a pointeur sur l'arbre 					                 	*/
/*			  c caractére à insérer dans le nouveau noeud 					*/
/*                                                                      	*/
/* En sortie: adresse du nouveau noeud inséré								*/
/* ------------------------------------------------------------------------ */
Noeud_t * InsertionHorizontal(Noeud_t *a ,char c)
{
	Noeud_t *n=NULL;
	
	n=InitNoeud();
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

/* ------------------------------------------------------------------------ */
/* CreerArbre     Créer un arbre à partir d'une chaîne de caractéres   		*/
/*                                                                      	*/
/* En entrée: c chaîne de caractéres pour créer l'arbre 			 		*/
/*			  nbExp nombre de caractéres dans la chaîne						*/
/*                                                                      	*/
/* En sortie: adresse du premier noeud de l'arbre							*/
/* ------------------------------------------------------------------------ */
Noeud_t * CreerArbre(char *c, int nbExp)
{
	int i=0;
	pile_t *p;
	elt_t elt_p;
	Noeud_t *a=NULL;

	p=InitPile(nbExp);

	while(i < nbExp)
	{
		switch(c[i])
		{
			case '(' :
			{
				a=InsertionVertical(a, c[i+1]);
				elt_p.adr = a;
				Empiler(p, elt_p);
				i++;
				break;
			}	
			case ',' :
			{
				a=InsertionHorizontal(a, c[i+1]);
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
				a=InsertionHorizontal((p->val[p->nb_elt]).adr, c[i]);
				break;	
		}
		i++;
	}
	LibererPile(p);
	return a;
}

/* ------------------------------------------------------------------------ */
/* AffichagePostFixe     Affichage de l'arbre en postfixé 			   		*/
/*                                                                      	*/
/* En entrée: a pointeur sur le premier noeud de l'arbre 			 		*/
/*			  nbEexp nombre de caractéres dans le fichier 					*/
/*                                                                      	*/
/* En sortie: 																*/
/* ------------------------------------------------------------------------ */
void AffichagePostFixe(Noeud_t *a, int nbExp)
{
	elt_t cour,prec;
	pile_t *p;
	
	p=InitPile(nbExp);
	cour.adr=a;
	printf("\nAffichage post fixé de l'arbre : \n");
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

/* ------------------------------------------------------------------------ */
/* Rechercher     		Affichage de l'arbre en postfixé 			   		*/
/*                                                                      	*/
/* En entrée: a pointeur sur le premier noeud de l'arbre 			 		*/
/*			  c caractére à rechercher dans l'arbre 						*/
/*			  nbEexp nombre de caractéres dans le fichier 					*/
/*                                                                      	*/
/* En sortie: noeud pointeur de pointeur sur le noeud recherché				*/
/* ------------------------------------------------------------------------ */
int Rechercher(Noeud_t *a, Noeud_t ** noeud, char c, int nbExp)
{
	Noeud_t * cour;	
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
		printf("Le noeud n'a pas été trouvé\n");
	}
	LibererFile(f);

	return erreur;
}

/* ------------------------------------------------------------------------ */
/* InsertionFils     		Insertion d'un fils						   		*/
/*                                                                      	*/
/* En entrée: a pointeur sur le premier noeud de l'arbre 			 		*/
/*			  r caractére à rechercher dans l'arbre 						*/
/*			  v carcatére du nouveau noeud 									*/
/*			  nbEexp nombre de caractéres dans le fichier 					*/
/*                                                                      	*/
/* En sortie: 																*/
/* ------------------------------------------------------------------------ */
void InsertionFils(Noeud_t *a, char r, char v, int nbExp)
{
	Noeud_t *cour,*prec;
	Noeud_t **noeud;

	if(Rechercher(a,&cour,r,nbExp))
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
		*noeud = InitNoeud();
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

/* ------------------------------------------------------------------------ */
/* LibererArbre     		Libére la mémoire occupée par l'arbre	   		*/
/*                                                                      	*/
/* En entrée: a pointeur sur le premier noeud de l'arbre 			 		*/
/*			  nbEexp nombre de caractéres dans le fichier 					*/
/*                                                                      	*/
/* En sortie: 																*/
/* ------------------------------------------------------------------------ */
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
