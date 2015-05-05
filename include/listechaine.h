#ifndef LISTECHAINE_H_
#define LISTECHAINE_H_

#include <stdio.h>
#include <stdlib.h>
#include "polyedre.h"
#include "sommet.h"

pPoloptim initlistech(unsigned int nbrepoint, unsigned int nbreface, unsigned int nbrearete);
pPoloptim adjqch(char type, pPoloptim poly, void* data);
pPoloptim adjtch(char type, pPoloptim poly, void* data);
pPoloptim adjich(char type, pPoloptim poly, void* data, unsigned int i);
pPoloptim supqch(char type, pPoloptim poly);
pPoloptim suptch(char type, pPoloptim poly);
pPoloptim supich(char type, pPoloptim poly, unsigned int i);
void * tete(char type, pPoloptim poly);
void * suivant(char type, void *data);
int est_vide(char type, pPoloptim poly);
int longueurch(char type, pPoloptim poly);
void freeoptim(char type, pPoloptim poly);

#endif
