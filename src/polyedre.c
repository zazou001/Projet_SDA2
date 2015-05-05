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
	int j,k;
	for(j=0;j<nbrearete;j++){
		if(i==p.A->ldata[j]){
			for(k=0;p.F->ldata[k].idebut <= j;k++);
			listface->length +=1;
			listface->ldata=realloc(listface->ldata,(listface->length)*sizeof(int));				
			listface->ldata[listface->length-1] = k-1;
			}
	}
	return *listface;
}
ListInt FaceAdjacentes(polyedre p, int i){
	ListInt *listface = malloc(sizeof(ListInt));
	listface->length = 0;
	listface->ldata = NULL;
	int j,k,l;
	for(j=p.F->ldata[i].idebut;j<p.F->ldata[i].idebut+p.F->ldata[i].nbrearete;j++)
	{
		for(l=0;l<p.A->length;l++){
			if(p.A->ldata[j]==p.A->ldata[l]){
				for(k=0;p.F->ldata[k].idebut <= l;k++);
				listface->length +=1;
				listface->ldata=realloc(listface->ldata,(listface->length)*sizeof(int));				
				listface->ldata[listface->length-1] = k-1;
			}
		}
	}
	qsort (listface->ldata, listface->length, sizeof (int), compareints);
	j=0;
	while(j<listface->length)
	{
		if(listface->ldata[j] == i){
			for(k=j;k<listface->length;k++)
			{
				listface->ldata[k] = listface->ldata[k+1];
			}
			listface->length -=1;
		}
		else if(listface->ldata[j] != listface->ldata[j+1])
		{
			for(k=j;k<listface->length;k++)
			{
				listface->ldata[k] = listface->ldata[k+1];
			}
			listface->length -=1;
		}
		else j++;
	}
	return *listface;
}

ListInt FaceConnectees(polyedre p, int i){
	ListInt *listface = malloc(sizeof(ListInt));
	listface->length = 0;
	listface->ldata = NULL;
	int j,k,l;
	for(j=p.F->ldata[i].idebut;j<p.F->ldata[i].idebut+p.F->ldata[i].nbrearete;j++)
	{
		for(l=0;l<p.A->length;l++){
			if(p.A->ldata[j]==p.A->ldata[l]){
				for(k=0;p.F->ldata[k].idebut <= l;k++);
				listface->length +=1;
				listface->ldata=realloc(listface->ldata,(listface->length)*sizeof(int));				
				listface->ldata[listface->length-1] = k-1;
			}
		}
	}
	qsort (listface->ldata, listface->length, sizeof (int), compareints);
	j=0;
	while(j<listface->length)
	{
		if(listface->ldata[j] == i){
			for(k=j;k<listface->length;k++)
			{
				listface->ldata[k] = listface->ldata[k+1];
			}
			listface->length -=1;
		}
		else if(listface->ldata[j] == listface->ldata[j+1])
		{
			for(k=j;k<listface->length;k++)
			{
				listface->ldata[k] = listface->ldata[k+1];
			}
			listface->length -=1;
		}
		else j++;
	}
	return *listface;
}

/*int Connexe(polyedre p, polyedre cc[]){
	return 0;
}*/
