#ifndef POLYEDRE_H_
#define POLYEDRE_H

#include "sommet.h"
typedef struct{
	sommet *lPoints;
}ListPoints;

typedef struct{
	face *laretes;
}ListInt;

typedef struct{
	face *lFaces;
}ListFaces;

typedef struct{
	ListPoints S;
	ListInt A;
	ListFaces F;
}polyedre,*pPolyedre;


/*NbSommet(p) -> renvoie le nombre de sommets du polyèdre p
NbFace(p) -> renvoie le nombre de faces du polyèdre p
GetSommet(p,i) -> renvoie le Point correspondant au sommet numéro i.
NbSommetFace(p,i) -> renvoie le nombre de sommets de la face numéro i.
SommetFace(p,i,j) -> renvoie l'indice du j ème sommet de la face numéro i.*/

#endif
