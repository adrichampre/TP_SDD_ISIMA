#include "tp1.h"


int main(int argc, char **argv)
{
	int k;
	if(argc < 2 || argc > 3)
	{
		printf("Le nombre d'arguments est incorrect !\n");
		exit(1);
	}
	if(argc == 2)
	{
		k = 0;
	}
	else k = atoi(argv[2]);
	global(argv[1],k);
	
	return 0;
}
