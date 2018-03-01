#include "tp1.h"


Liste convertirMatrice(int **mat, int m, int n, int k)
{
	int i,usine,min = 0;
	Liste l;
	l = nouvelleListe();
	for(i=0;i<k;i++)
	{
		min = minimumTab(mat,m,n,min,&usine);
		l = insererEnTete(l,min,usine); // Peut aussi choisir d'inserer en fin
	}
	return l;
}

int minimumTab(int **mat, int m, int n, int min, int *usine)
{
	int i,j,tmp;

	tmp = mat[0][0];

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(mat[i][j] > min && mat[i][j] < tmp)
			{
				tmp = mat[i][j];
				*usine = i;
			}
		}
	}

	return tmp;
}



int ** chargement(char nomFichier[], int * m, int * n)
{
	FILE *f;
	int i,j, ** mat;
	
	f=fopen(nomFichier,"r");
	if(f == NULL)
	{
		printf("Probleme de lecture\n");
		exit(1);
	}
	fscanf(f,"%d%*c %d%*c",m,n);
	mat = (int **)malloc(*m * sizeof(int));
	if(mat == NULL)
	{
		printf("Probleme d'allocation\n");
		exit(2);
	}

	for(i=0;i<*m;i++)
	{
		mat[i] = (int *)malloc(*n * sizeof(int));
		if(mat[i] == NULL)
		{
			printf("Probleme d'allocation\n");
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


void sauvegarde(char *nomFichier, Liste l)
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
		fprintf(f, "%d ", l->periode);
		fprintf(f, "\n");
		l = l->suiv;
	}

	fclose(f);
}


void afficherElt(Liste l)
{
	printf("Usien : %d Valeur :%d ",l->usine, l->periode);
}

Liste insererEnTete(Liste l, int val, int usine)//A finir !!!!!!
{
	maillon *m;
	int i;
	
	m = (maillon *)malloc(sizeof(maillon));
	if(m == NULL)
	{
		printf("Probleme d'allocation\n");
		exit(2);
	}

	m->periode = val;
	m->usine = usine;
	m->suiv = l;

	return m;
}

/*Liste insererEnFin(Liste l, int *periode, int n)
{
	maillon *m,*a;
	int i;

	
	m = (maillon *)malloc(sizeof(maillon));
	if(m == NULL)
	{
		printf("Probleme d'allocation\n");
		exit(2);
	}

	m->periode = (int *)malloc(sizeof(int)*n);
	if(m->periode == NULL)
	{
		printf("Probleme d'allocation\n");
		exit(2);
	}

	m->suiv = nouvelleListe();
	for(i=0;i<n;i++)
	{
		m->periode[i] = periode[i];	
	}

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
}*/


Liste nouvelleListe(void)
{
	return NULL;
}

void libererListe(Liste l)
{
	maillon *m;
	while(l!=NULL)
	{
		m = l;
		l = l->suiv;
		libererElt(m);
	}
}

void libererElt(maillon *m)
{
	free(m);
}

Liste supprPremierElt(Liste l)
{
	maillon *m;

	m=l;
	l=l->suiv;
	libererElt(m);

	return l;
}

Liste supprElt(maillon *prec, maillon *suppr)
{
	prec->suiv = suppr->suiv;
	libererElt(suppr);

	return prec;
}

void afficherListe(Liste l)
{
	int i;

	while(l!=NULL)
	{
		printf("%d ", l->periode);
		printf("\n");
		l=l->suiv;
	}
}

void global(char argv[], int k)
{
	int ** mat, m, n;
	Liste l;
	
	mat = chargement(argv,&m,&n);

	if(k == 0)
		k = m*n;

	printf("Matrice du fichier : \n");
	afficherMatrice(mat,m,n);
	printf("\n");

	l=convertirMatrice(mat,m,n,k);
	printf("Liste chaine : \n");
	//afficherListe(l,m,n);

	//l = supprUsine(l, 0, n);

	afficherListe(l);

	sauvegarde("liste.txt",l);
	libererMatrice(mat,m);
	libererListe(l);
}
