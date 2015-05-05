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
	ListInt *listface = malloc(sizeof(ListInt)+sizeof(int));
	/*int nbrearete = sizeof(p.A)/sizeof(arete);
	int nbreface = NbFace(p);
	int Face = 0;
	int j,k;
	for(j=0;j<nbrearete;j++){
		if(i==p.A.laretes[j]){
			for(k=0;p.F.lFaces[k].cote[0] <= j||k<nbreface;k++){}
			Face++;	
			listface=realloc(listface,sizeof(ListInt)+Face*sizeof(int));				
			listface->lInt[Face-1] = k-1;
			}
	}
	listface->lInt[Face] = -1;*/
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
