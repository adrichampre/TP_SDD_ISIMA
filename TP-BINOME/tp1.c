#include "tp1.h"


liste_t convertirMatrice(int ** mat, int m, int n, int k)
{
	int i;
	usine_t tab[m*n];
	liste_t l;
	l = nouvelleListe();
	triTab(tab,mat,m,n);
	for(i=0;i<k;i++)
	{
		l = insererEnFin(l,tab[i].periode, tab[i].coutProd, tab[i].numero);
	}
	return l;
}

void triTab(usine_t * tab, int ** mat, int m, int n) 
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

int ** chargement(char * nomFichier, int * m, int * n)
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

void afficherMatrice(int ** mat, int m, int n)
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

void libererMatrice(int ** mat, int m)
{
	int i;
	
	for(i=0;i<m;i++)
	{
		free(mat[i]);
	}
	free(mat);
}


liste_t supprUsine(liste_t l, int u)
{
	maillon_t * a;
	
		while(l!=NULL && l->u.numero == u)
		{
			l = supprPremierElt(l);
		}

		if(l != NULL)
		{
			a=l;
			while(a->suiv!=NULL)
			{
				if(a->suiv->u.numero == u)
				{
					a = supprElt(a, a->suiv);
				}
				else
				{
					a = a->suiv;
				}
			}
		}
	
	return l;
}


void sauvegarde(char * nomFichier, liste_t l)
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

void global(char argv[], int *k)
{
	int ** mat, m, n;
	liste_t l;
	
	mat = chargement(argv,&m,&n);

	if(*k==0)
		*k = m*n;
	printf("\nK : %d\n\n",* k);
	printf("Matrice du fichier : \n");
	afficherMatrice(mat, m, n);

	l=convertirMatrice(mat, m, n, * k);
	printf("liste_t chaine : \n");

	afficherListe(l);

	l = supprUsine(l, 2);

	printf("\nAprès suppression des usines :\n\n");

	afficherListe(l);
	
	sauvegarde("liste_t.txt",l);

	libererMatrice(mat, m);
	libererListe(l);
}
