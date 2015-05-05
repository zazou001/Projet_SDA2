#ifndef POLYEDRE_H_
#define POLYEDRE_H_

#include <stdio.h>
#include <stdlib.h>
#include "sommet.h"

typedef struct{
	int length;
	sommet *ldata;
}ListPoints;

typedef struct{
	int length;
	arete *ldata;
}ListArete;

typedef struct{
	int length;
	face *ldata;
}ListFaces;

typedef struct{
	int length;
	int *ldata;
}ListInt;

typedef struct{
	ListPoints *S;
	ListArete *A;
	ListFaces *F;
}polyedre,*pPolyedre;


/*int NbSommet(polyedre p);
int NbFace(polyedre p);
sommet GetSommet(polyedre p,int i);
int NbSommetFace(polyedre p, int i);
int SommetFace(polyedre p,int i, int j);
ListInt FaceIncidentes(polyedre p, int i);
ListInt FaceConnectees(polyedre, int p);
int Connexe(polyedre p, polyedre cc[]);*/


#endif
