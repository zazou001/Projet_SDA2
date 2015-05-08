#ifndef TABLE_H_
#define TABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include "listechaine.h"
#include "sommet.h"

typedef struct{
	int length;
	listc *chaine;
}tablistc, *pTablistc;

pTablistc initable(int t);
pTablistc ajoute(pTablistc t, int i, int d);
pTablistc retire(pTablistc t, int i, int d);
int element(tablistc t, int i, int j);
int card(tablistc t);
int estvide(tablistc t);
int appartient(tablistc t, int i,int d);
void freetable(tablistc *t);

#endif
