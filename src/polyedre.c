#include "polyedre.h"
int NbSommet(polyedre p){
	return longueur(3,&p);
}
int NbFace(polyedre p){
	return longueur(2,&p);
}
sommet GetSommet(polyedre p,int i){
	return p.S->ldata[i-1];
}
int NbSommetFace(polyedre p, int i){
	return p.F->ldata[i-1].nbrearete;
}
int SommetFace(polyedre p,int i, int j){
	if(NbSommetFace(p,i)<(j))
		exit(EXIT_FAILURE);
	return p.A->ldata[p.F->ldata[i-1].idebut+j-1];
}

ListInt FaceIncidentes(polyedre p, int i){
	ListInt *listface = malloc(sizeof(ListInt));
	listface->length = 0;
	listface->ldata = NULL;
	int nbrearete = longueur(1,&p);
	int nbreface = NbFace(p);
	int j,k;
	for(j=0;j<nbrearete;j++){
		if(i==p.A->ldata[j]){
			for(k=0;p.F->ldata[k].idebut <= j||k<nbreface;k++);
			listface->length +=1;
			listface->ldata=realloc(listface->ldata,(listface->length)*sizeof(int));				
			listface->ldata[listface->length-1] = k-1;
			}
	}
	for(j=0;j<listface->length;j++)
	{
		printf("[%u]\n",listface->ldata[j]);
	}
	return *listface;
}
/*ListInt FaceAdjacentes(polyedre p, int i){
	
return NULL;
}
ListInt FaceConnectees(polyedre p, int i){
	
	return NULL;
}

/*int Connexe(polyedre p, polyedre cc[]){
	return 0;
}*/
