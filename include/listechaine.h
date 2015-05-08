#ifndef LISTECHAINE_H_
#define LISTECHAINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "polyedre.h"
#include "sommet.h"

typedef struct maillon {
	int data;
	struct maillon *s;
}maillon, *pMaillon;

typedef struct{
	int length;
	pMaillon chaine;
}listc, *pListc;


listc initlistech();
listc adjqch(listc liste, int data,...);
listc adjtch(listc liste, int data,...);
listc adjich(unsigned int i, listc liste, int data,...);
listc supqch(listc liste);
listc suptch(listc liste);
listc supich(listc liste, unsigned int i);
maillon tete(listc liste);
maillon suivant(maillon m);
int est_vide(listc liste);
int longueurch(listc liste);
void freech(pMaillon m);

#endif
