#ifndef LISTE_H_
#define LISTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
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

void* adjq(void *liste,int type, ...);
void* adjt(void *liste,int type, ...);
void* adji(unsigned int i, void *liste, int type,...);
void* supq(int type, void *liste);
void* supt(int type, void *liste);
void* supi(int type, void *liste, unsigned int i);
int longueur(int type, void *liste);
void freeliste(int type, void *liste);

#endif
