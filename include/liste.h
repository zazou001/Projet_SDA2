#ifndef LISTE_H_
#define LISTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "polyedre.h"
#include "sommet.h"

pPolyedre initliste(unsigned int nbrepoint, unsigned int nbreface, unsigned int nbrearete);
void* adjq(void *liste,int type, ...);
void* adjt(void *liste,int type, ...);
void* adji(unsigned int i, void *liste, int type,...);
void* supq(int type, void *liste);
void* supt(int type, void *liste);
void* supi(int type, void *liste, unsigned int i);
int longueur(int type, void *liste);
void freeliste(int type, void *liste);

#endif
