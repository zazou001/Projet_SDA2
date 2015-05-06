#ifndef LISTECHAINE_H_
#define LISTECHAINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "polyedre.h"
#include "sommet.h"

typedef struct{
	int length;
	pMaillon chaine;
}listc, *pListc;

typedef struct{
	int data;
	pMaillon s;
}maillon, *pMaillon;

listc initlistech();
listc adjqch(listc liste, ...);
listc adjtch(listc liste, ...);
listc adjich(unsigned int i, listc liste,...);
listc supqch(listc liste);
listc suptch(listc liste);
listc supich(listc liste, unsigned int i);
void * tete(char type, listc liste);
void * suivant(char type, void *data);
int est_vide(char type, listc liste);
int longueurch(char type, listc liste);
void freeoptim(char type, listc liste);

#endif
