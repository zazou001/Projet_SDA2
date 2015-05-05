#ifndef SOMMET_H_
#define SOMMET_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float x;
	float y;
	float z;
}sommet, *pSommet;

typedef struct{
	unsigned int idebut;
	unsigned int nbrearete;
}face, *pFace;

typedef unsigned int arete;

int compareints (const void * a, const void * b);

#endif
