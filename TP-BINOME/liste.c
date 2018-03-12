/* -------------------------------------------------------------------- */
/*            Fichier contenant les fonctions de liste                  */
/*                                                                      */
/* -------------------------------------------------------------------- */

#include "liste.h"


/* -------------------------------------------------------------------- */
/* InsererEnTete          Insére un maillon en tête de liste            */
/*                                                             			*/
/* En entrée: l est la liste chaînée où la fonction ajoute un maillon  	*/
/*			  u représente l'usine qui sera ajouté dans le maillon 		*/
/*																		*/
/* En sortie: la liste chaînée l avec un maillon supplémentaire			*/
/* -------------------------------------------------------------------- */

liste_t InsererEnTete(liste_t l, usine_t u)
{
	maillon_t * m;
	
	m = (maillon_t *)malloc(sizeof(maillon_t));
	
	if(m == NULL)
	{
		printf("Erreur : Probleme d'allocation\n");
		exit(2);
	}

	m->u.periode = u.periode;
	m->u.coutProd = u.coutProd;
	m->u.numero = u.numero;
	
	m->suiv = l;

	return m;
}

/* -------------------------------------------------------------------- */
/* InsererEnFin          Insére un maillon en fin de liste 	            */
/*                                                             			*/
/* En entrée: l est la liste chaînée où la fonction ajoute un maillon  	*/
/*			  u représente l'usine qui sera ajouté dans le maillon 		*/
/*																		*/
/* En sortie: la liste chaînée l avec un maillon supplémentaire			*/
/* -------------------------------------------------------------------- */

liste_t InsererEnFin(liste_t l, usine_t u)
{
	maillon_t * m,* a;

	
	m = (maillon_t *)malloc(sizeof(maillon_t));
	if(m == NULL)
	{
		printf("Erreur : Probleme d'allocation\n");
		exit(2);
	}

	m->suiv = NouvelleListe();
	

	m->u.periode = u.periode;
	m->u.coutProd = u.coutProd;
	m->u.numero = u.numero;

	if(l != NULL)
	{

		a=l;

		while(a->suiv != NULL)
		{
			a = a->suiv;
		}

		a->suiv = m;

	}
	else
	{
		l = m;
	}
		
	return l;
}

/* -------------------------------------------------------------------- */
/* NouvelleListe          Renvoie NULL pour faire une nouvelle liste    */
/*                                                             			*/
/* En entrée:														    */
/*																		*/
/* En sortie: retourne NULL 											*/
/* -------------------------------------------------------------------- */

liste_t NouvelleListe(void)
{
	return NULL;
}

/* -------------------------------------------------------------------- */
/* LibererListe        Libére la mémoire occupé par la liste chaînée    */
/*                                                             			*/
/* En entrée: l est la liste chaînée à libérer						    */
/*																		*/
/* En sortie:															*/
/* -------------------------------------------------------------------- */

void LibererListe(liste_t l)
{
	maillon_t * m;

	while(l!=NULL)
	{
		m = l;
		LibererElt(m);
		l = l->suiv;
	}
}

/* ------------------------------------------------------------------------------ */
/* LibererElt        Libére la mémoire occupé d'un maillon de la liste chaînée    */
/*                                                             					  */
/* En entrée: m est le maillon à libérer						    		  	  */
/*																				  */
/* En sortie:																	  */
/* ------------------------------------------------------------------------------ */

void LibererElt(maillon_t * m)
{
	free(m);
}

/* -------------------------------------------------------------------- */
/* SupprPremierElt        Supprime le premier maillon de la liste       */
/*                                                             			*/
/* En entrée: l est la liste chaînée						    		*/
/*																		*/
/* En sortie: la liste chaînée avec le premier maillon supprimé 	    */
/* -------------------------------------------------------------------- */

liste_t SupprPremierElt(liste_t l)
{
	maillon_t * m;

	if (l != NULL)
	{
		m=l;
		l=l->suiv;
		LibererElt(m);
	}
	else
	{
		l = NULL;
	}
	return l;
}

/* ----------------------------------------------------------------------------------- */
/* SupprElt        Supprime un élément de la liste chaînée    						   */
/*                                                             						   */
/* En entrée: prec est le pointeur sur le maillon précédent à celui qu'on supprimera   */
/*			  suppr est le pointeur sur le maillon à supprimer 						   */
/*																					   */
/* En sortie: renvoie le pointeur prec												   */
/* ----------------------------------------------------------------------------------- */

liste_t SupprElt(maillon_t * prec, maillon_t *suppr)
{
	prec->suiv = suppr->suiv;
	LibererElt(suppr);

	return prec;
}

/* -------------------------------------------------------------------- */
/* AfficherListe        	  Afficher la liste chaînée			   	    */
/*                                                             			*/
/* En entrée: l est la liste chaînée à afficher					    	*/
/*																		*/
/* En sortie:															*/
/* -------------------------------------------------------------------- */

void AfficherListe(liste_t l)
{	
	printf("----------------------------------------\n");
	printf("| Usine | periode | cout de production |\n");
	printf("|--------------------------------------|\n");
	
	while(l!=NULL)
	{
		printf("|   %d\t|    %d\t  |\t    %d\t       |\n",l->u.numero, l->u.periode, l->u.coutProd);
		if(l->suiv==NULL) printf("----------------------------------------\n");	
		else printf("|--------------------------------------|\n");
		l=l->suiv;
	}
}