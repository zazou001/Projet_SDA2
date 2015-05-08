#ifndef POLYEDRE_H_
#define POLYEDRE_H_

#include <stdio.h>
#include <stdlib.h>
#include "sommet.h"
#include "liste.h"

typedef struct{
	ListPoints *S;
	ListArete *A;
	ListFaces *F;
}polyedre,*pPolyedre;

pPolyedre initliste(unsigned int nbrepoint, unsigned int nbreface, unsigned int nbrearete);
int NbSommet(polyedre p);
int NbFace(polyedre p);
sommet GetSommet(polyedre p,int i);
int NbSommetFace(polyedre p, int i);
int SommetFace(polyedre p,int i, int j);
ListInt FaceIncidentes(polyedre p, int i);
ListInt FaceAdjacentes(polyedre p, int i);
ListInt FaceConnectees(polyedre, int p);
int Connexe(polyedre p, polyedre cc[]);


#endif
