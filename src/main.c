#include <stdio.h>
#include <stdlib.h>

#include "polyedre.h"
//#include "poloptim.h"
#include "fichier.h"
         
int main(int argc, char *argv[]){
	
	if(argc > 2) {printf("Y en a trop d'arguments.\n"); return 1;}
	if(argc == 1) {printf("Pas assez d'arguments.\n"); return 2;}
	
	pPolyedre poly;
	poly = init(argv[1]);
	printf("%d\n", NbSommet(*poly));
	printf("%d\n", NbFace(*poly));
	FaceIncidentes(*poly,2);
	free(poly);
	
	return EXIT_SUCCESS;
}
