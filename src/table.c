#include "table.h"

tablistc initable(int t);
tablistc ajoute(tablistc t, int i, int d);
tablistc retire(tablistc t, int i, int d);
int element(tablistc t, int i, int j);
int card(tablistc t);
int estvide(tablistc t);
int appartient(tablistc t, int i,int d);
void freetable(tablistc *t);
