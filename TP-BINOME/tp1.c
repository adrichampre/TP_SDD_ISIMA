#include "tp1.h"



Liste convertirMatrice(int **mat, int m, int n, int k)
{
	int i,min = 0;
	Usine tab[m*n];
	Liste l;
	l = nouvelleListe();
	triTab(tab,mat,m,n);
	for(i=0;i<k;i++)
	{
		l = insererEnFin(l,tab[i].periode, tab[i].coutProd, tab[i].numero); // Peut aussi choisir d'inserer en fin
	}
	return l;
}

void triTab(Usine *tab, int **mat, int m, int n) 
{ 
	Usine tmp;
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

int ** chargement(char nomFichier[], int * m, int * n)
{
	FILE *f;
	int i,j, ** mat;
	
	f=fopen(nomFichier,"r");
	if(f == NULL)
	{
		printf("Erreur : Probleme de lecture\n");
		exit(1);
	}
	fscanf(f,"%d%*c %d%*c",m,n);
	mat = (int **)malloc(*m * sizeof(int));
	if(mat == NULL)
	{
		printf("Erreur : Probleme d'allocation\n");
		exit(2);
	}

	for(i=0;i<*m;i++)
	{
		mat[i] = (int *)malloc(*n * sizeof(int));
		if(mat[i] == NULL)
		{
			printf("Erreur : Probleme d'allocation\n");
			exit(2);
		}
		for(j=0;j<*n;j++)
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

void libererMatrice(int **mat, int m)
{
	int i;
	
	for(i=0;i<m;i++)
	{
		free(mat[i]);
	}
	free(mat);
}


Liste supprUsine(Liste l, int u, int m)
{
	maillon *a;
	int i;

	a=l;

	if(u == 0)
	{
		l = supprPremierElt(l);
	}
	else
	{
		for (i = 0; i < u; ++i)
		{
			a = a->suiv;
		}
		a = supprElt(a, a->suiv);
	}

	return l;

}


void sauvegarde(char *nomFichier, Liste l, int n)
{
	FILE *f;
	int i;

	f=fopen(nomFichier,"w");
	if(f==NULL)
	{
		printf("Probleme d'ouverture de fichier\n");
		exit(1);
	}

	while(l != NULL)
	{
		for (i = 0; i < n; ++i)
		{
			fprintf(f, "%d ", l->u.coutProd);
		}
		fprintf(f, "\n");
		l = l->suiv;
	}

	fclose(f);
}

void global(char argv[], int *k)
{
	int ** mat, m, n;
	Liste l;
	
	mat = chargement(argv,&m,&n);

	if(*k==0)
		*k = m*n;
	printf("\n%d\n",*k);
	printf("Matrice du fichier : \n");
	afficherMatrice(mat,m,n);

	l=convertirMatrice(mat,m,n,*k);
	printf("Liste chaine : \n");
	
	//l = supprUsine(l, 0, n);
	
	
	afficherListe(l);
	sauvegarde("liste.txt",l,n);
	libererMatrice(mat,m);
	libererListe(l);
}
