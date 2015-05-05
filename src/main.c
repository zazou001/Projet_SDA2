#include <stdio.h>
#include <stdlib.h>

#include "polyedre.h"
//#include "poloptim.h"
#include "fichier.h"
         
int main(int argc, char *argv[]){
	
	if(argc > 2) {printf("Y en a trop d'arguments.\n"); return 1;}
	if(argc == 1) {printf("Pas assez d'arguments.\n"); return 2;}
	
	pPolyedre poly;
	int j;
	poly = init(argv[1]);
<<<<<<< HEAD
	ListInt listface = FaceConnectees(*poly,2);
	for(j=0;j<listface.length;j++)
	{
		printf("[%u]\n",listface.ldata[j]);
	}
	freeliste(3,poly->S);
=======
	printf("%d\n", NbSommet(*poly));
	printf("%d\n", NbFace(*poly));
	FaceIncidentes(*poly,2);
	free(poly);
>>>>>>> c4e1f94add655dfd3f7b3a80ad02525e5c5b8fe1
	
	return EXIT_SUCCESS;
}
