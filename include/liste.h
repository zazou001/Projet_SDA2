#ifndef LISTE_H_
#define LISTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "polyedre.h"
#include "sommet.h"

pPolyedre initliste(unsigned int nbrepoint, unsigned int nbreface, unsigned int nbrearete);
pPolyedre adjq(pPolyedre poly,int type, ...);
pPolyedre adjt(pPolyedre poly,int type, ...);
pPolyedre adji(unsigned int i, pPolyedre poly, int type,...);
pPolyedre supq(int type, pPolyedre poly);
pPolyedre supt(int type, pPolyedre poly);
pPolyedre supi(int type, pPolyedre poly, unsigned int i);
int longueur(int type, pPolyedre poly);
void printlist(int type, pPolyedre poly);
void freeliste(pPolyedre poly);

#endif
