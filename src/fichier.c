#include "fichier.h"

pPolyedre init(char* fichier){
	
	FILE * pFiles = NULL;
	pFiles = fopen(fichier,"r");
	char off[5];
	pPolyedre p;
	unsigned int nbrepoint, nbreface, nbrearete;
	unsigned int areteface, iarete;
	unsigned int i, j, k=0;
	double x, y, z;
	
	if (pFiles == NULL) {printf("Erreur d'ouverture du fichier.\n"); exit(EXIT_FAILURE);}
	fscanf(pFiles,"%s",off);
	if(strcmp(off,"OFF")!=0){printf("Le fichier n'est pas un OFF.\n"); exit(EXIT_FAILURE);}
	fscanf(pFiles,"%u %u %u", &nbrepoint, &nbreface, &nbrearete);
	p = initliste(nbrepoint, nbreface, nbrearete);
	for(i=0;i<nbrepoint;i++){
		fscanf(pFiles,"%lf %lf %lf",&x, &y, &z);
		adjq(p->S, 3, x, y, z);
	}
	for(i=0;i<nbreface;i++){
		fscanf(pFiles,"%u",&areteface);
		adjq(p->F,2,k,areteface);
		for(j=0;j<areteface;j++){
			fscanf(pFiles,"%u",&iarete);
			adjq(p->A,1,iarete);
		}
		k += areteface;
	}
	return p;
	
}
