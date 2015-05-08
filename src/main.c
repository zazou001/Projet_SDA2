#include <stdio.h>
#include <stdlib.h>

#include "polyedre.h"
#include "liste.h"
#include "poloptim.h"
#include "fichier.h"
         
int main(int argc, char *argv[]){
	
	if(argc > 2) {printf("Y en a trop d'arguments.\n"); return 1;}
	if(argc == 1) {printf("Pas assez d'arguments.\n"); return 2;}
	
	pPolyedre poly;
	int j;
	poly = init(argv[1]);
	ListInt listface = FaceConnectees(*poly,2);
	poloptim p = convertir(*poly);
	//FaceAdjacentesoptim(p,1);
	for(j=0;j<listface.length;j++)
	{
		printf("[%u]\n",listface.ldata[j]);
	}
	freeliste(3,poly->S);
	freeliste(2,poly->F);
	freeliste(1,poly->A);
	free(poly);
	return EXIT_SUCCESS;
}
