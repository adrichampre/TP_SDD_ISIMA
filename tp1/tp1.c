/* -------------------------------------------------------------------- */
/*          Fichier contenant les fonctions spécifique au tp            */
/*                                                                      */
/* -------------------------------------------------------------------- */


#include "tp1.h"


/* -------------------------------------------------------------------------------------------------------------- */
/* ConvertirMatrice          Convertie notre matrice en liste chaînée triée (ordre croissant) avec k valeurs      */
/*                                                             													  */
/* En entrée: mat matrice d'entier contenant les coûts de production des usines  								  */
/*			  m nombre d'usine																					  */
/*			  n nombre de période																				  */
/*			  k nombre de valeur à conserver																	  */
/*																												  */
/* En sortie: la liste chaînée l triée en ordre croissant													      */
/* -------------------------------------------------------------------------------------------------------------- */

liste_t ConvertirMatrice(int ** mat, int m, int n, int k)
{
	int i;
	usine_t tab[m*n];
	liste_t l;

	l = NouvelleListe();
	TriTab(tab,mat,m,n);
	for(i=0;i<k;i++)
	{
		l = InsererEnFin(l,tab[i]);
	}
	return l;
}

/* ----------------------------------------------------------------------------------------------- */
/* TriTab          Tri un tableau d'usine en ordre croissant de leur coût de production            */
/*                                                             									   */
/* En entrée: tab est le tableau à rendre trié 												   */
/*			  mat matrice d'entier contenant les coûts de production des usines 				   */
/*			  m nombre d'usine																	   */
/*			  n nombre de période																   */
/*																								   */
/* En sortie: tab le tableau des usines triées													   */
/* ----------------------------------------------------------------------------------------------- */

void TriTab(usine_t * tab, int ** mat, int m, int n) 
{ 
	usine_t tmp;
	int estTrie,cour, li,co,i, cpt=0; 

	for(li=0; li<m; li++)
	{
		for(co=0; co<n; co++)
		{
			tab[cpt].periode = co;
			tab[cpt].coutProd = mat[li][co];
			tab[cpt].numero = li;			
			cpt++;
		}
	}

	estTrie=-1;
	cour = 0;
	while(estTrie==-1)
	{				
		for(i=0; i < m*n - 1; i++) 
		{ 
			if(tab[i].coutProd > tab[i+1].coutProd) 
			{ 
				tmp.periode=tab[i].periode;
				tmp.coutProd=tab[i].coutProd; 
				tmp.numero=tab[i].numero;
				tab[i].periode=tab[i+1].periode;
				tab[i].coutProd=tab[i+1].coutProd;
				tab[i].numero=tab[i+1].numero;
				tab[i+1].periode = tmp.periode;
				tab[i+1].coutProd = tmp.coutProd;
				tab[i+1].numero = tmp.numero;				
				cour = -1;
			} 
		} 
		if(cour==-1)
			cour = 0;
		else estTrie = 1;
	}
}

/* ------------------------------------------------------------------------------------------------------- */
/* Chargement          Charge un fichier pour renvoyer une matrice des coût de production des usines       */
/*                                                             									   		   */
/* En entrée: nomFichier représente le nom de fichier que l'on doit charger 							   */
/*			  m pointeur sur le nombre d'usine															   */
/*			  n pointeur sur le nombre de période												   		   */
/*																								   		   */
/* En sortie: mat matrice des coûts de production des usines											   */
/*			  m nombre d'usine 																			   */
/*			  n nombre 																					   */
/* ------------------------------------------------------------------------------------------------------- */

int ** Chargement(char * nomFichier, int * m, int * n)
{
	FILE * f;
	int i,j, ** mat;
	
	f=fopen(nomFichier,"r");
	if(f == NULL)
	{
		printf("Erreur : Probleme de lecture\n");
		exit(1);
	}
	fscanf(f,"%d%*c %d%*c",m,n);
	mat = (int **)malloc(* m * sizeof(int));
	if(mat == NULL)
	{
		printf("Erreur : Probleme d'allocation\n");
		exit(2);
	}

	for(i=0;i<*m;i++)
	{
		mat[i] = (int *)malloc(* n * sizeof(int));
		if(mat[i] == NULL)
		{
			printf("Erreur : Probleme d'allocation\n");
			exit(2);
		}
		for(j=0;j<* n;j++)
		{
			fscanf(f,"%d%*c",mat[i]+j);
		}
	}
	fclose(f);
	
	return mat;
	
}


/* ----------------------------------------------------------------------------------------------- */
/* AfficherMatrice          Affiche toute la matrice de dimension m*n            				   */
/*                                                             									   */
/* En entrée: mat matrice d'entier contenant les coûts de production des usines 				   */
/*			  m nombre d'usine																	   */
/*			  n nombre de période																   */
/*																								   */
/* En sortie: 																					   */
/* ----------------------------------------------------------------------------------------------- */

void AfficherMatrice(int ** mat, int m, int n)
{
	int i,j;
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	printf("\n");
}


/* ----------------------------------------------------------------------------------------------- */
/* LibererMatrice          Libére l'espace occupé par la matrice            					   */
/*                                                             									   */
/* En entrée: mat matrice d'entier contenant les coûts de production des usines 				   */
/*			  m nombre d'usine																	   */
/*																								   */
/* En sortie: 																					   */
/* ----------------------------------------------------------------------------------------------- */

void LibererMatrice(int ** mat, int m)
{
	int i;
	
	for(i=0;i<m;i++)
	{
		free(mat[i]);
	}
	free(mat);
}

/* ----------------------------------------------------------------------------------------------- */
/* SupprUsine          Supprime de la liste chaînée tous les éléments d'une usine		           */
/*                                                             									   */
/* En entrée: l est la liste chaînée			 												   */
/*			  u numéro d'usine à supprimer de la liste chaînée					 				   */
/*																								   */
/* En sortie: l la nouvelle liste chaînée après suppression										   */
/* ----------------------------------------------------------------------------------------------- */

liste_t SupprUsine(liste_t l, int u)
{
	maillon_t * a;
	
	while(l!=NULL && l->u.numero == u)
	{
		l = SupprPremierElt(l);
	}
	if(l != NULL)
	{
		a=l;
		while(a->suiv!=NULL)
		{
			if(a->suiv->u.numero == u)
			{
				a = SupprElt(a, a->suiv);
			}
			else
			{
				a = a->suiv;
			}
		}
	}
	
	return l;
}

/* ----------------------------------------------------------------------------------------------- */
/* Sauvegarde          Sauvegarde la liste chaînée dans un fichier 						           */
/*                                                             									   */
/* En entrée: nomFichier est le nom du fichier où la sauvegarde sera effectuée 				   	   */
/*			  l liste chaînée à sauvegarder									 				   	   */
/*																								   */
/* En sortie: 																					   */
/* ----------------------------------------------------------------------------------------------- */

void Sauvegarde(char * nomFichier, liste_t l)
{
	FILE * f;

	f=fopen(nomFichier,"w");
	if(f==NULL)
	{
		printf("Probleme d'ouverture de fichier\n");
		exit(1);
	}

	fprintf(f, "Usine\tPeriode\t\tCout de production\n");

	while(l != NULL)
	{

		fprintf(f, "  %d\t\t  %d\t\t\t  %d\n", l->u.numero, l->u.periode, l->u.coutProd);
		l = l->suiv;
	}

	fclose(f);
}

/* ----------------------------------------------------------------------------------------------- */
/* Global       Fonction qui fait appel à toutes les autres fonctions nécessaire pour notre tp     */
/*                                                             									   */
/* En entrée: argv est le tableau de caractéres contenant les arguments						       */
/*			  k est le pointeur d'entier sur le nombre de valeurs  				   			       */
/*				à conserver dans la convertion de la matrice									   */
/*																								   */
/* En sortie: 																					   */
/* ----------------------------------------------------------------------------------------------- */

void Global(char argv[], int *k)
{
	int ** mat, m, n;
	liste_t l;

	mat = Chargement(argv,&m,&n);

	if(*k > m*n)
		*k = m*n;
	printf("\nK : %d\n\n",* k);
	printf("Matrice du fichier : \n");
	AfficherMatrice(mat, m, n);

	l=ConvertirMatrice(mat, m, n, * k);
	printf("Liste chaînée : \n");

	AfficherListe(l);

	l = SupprUsine(l, 1);

	printf("\nAprès suppression des usines :\n\n");

	AfficherListe(l);
	
	Sauvegarde("liste.txt",l);

	LibererMatrice(mat, m);
	LibererListe(l);
}
