#ifndef POLOPTIM_H_
#define POLOPTIM_H_

#include <stdio.h>
#include <stdlib.h>
#include "polyedre.h"
#include "sommet.h"
#include "liste.h"
#include "table.h"
#include "listechaine.h"

typedef struct{
	ListPoints *S;
	ListArete *A;
	ListFaces *F;
	tablistc *sa;
	tablistc *fi;
}poloptim, *pPoloptim;

poloptim convertir(polyedre p);
int NbSommetoptim(poloptim p);
int NbFaceoptim(poloptim p);
sommet GetSommetoptim(poloptim p,int i);
int NbSommetFaceoptim(poloptim p, int i);
int SommetFaceoptim(poloptim p,int i, int j);
ListInt FaceIncidentesoptim(poloptim p, int i);
ListInt FaceAdjacentesoptim(poloptim p, int i);
ListInt FaceConnecteesoptim(poloptim p, int i);
int Connexeoptim(poloptim p, poloptim cc[]);


#endif
