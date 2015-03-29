#ifndef POLYEDRE_H_
#define POLYEDRE_H_

#include <stdio.h>
#include <stdlib.h>
#include "sommet.h"
typedef struct{
	sommet lPoints[0];
}ListPoints;

typedef struct{
	arete laretes[0];
}ListArete;

typedef struct{
	face lFaces[0];
}ListFaces;

typedef struct{
	int lInt[0];
}ListInt;

typedef struct{
	ListPoints S;
	ListArete A;
	ListFaces F;
}polyedre,*pPolyedre;


int NbSommet(polyedre p);
int NbFace(polyedre p);
sommet GetSommet(polyedre p,int i);
int NbSommetFace(polyedre p, int i);
int SommetFace(polyedre p,int i, int j);
ListInt FaceIncidentes(polyedre p, int i);
ListInt FaceConnectees(polyedre, int p);
int Connexe(polyedre p, polyedre cc[]);


#endif
