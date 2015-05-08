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

tablistc initable(int t);
tablistc ajoute(tablistc t, int i, int d);
tablistc retire(tablistc t, int i, int d);
int element(tablistc t, int i, int j);
int card(tablistc t);
int estvide(tablistc t);
int appartient(tablistc t, int i,int d);
void freetable(tablistc *t);

#endif
