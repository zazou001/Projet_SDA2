#include "table.h"

pTablistc initable(int t)
{
	int i;
	tablistc *tab = malloc(sizeof(tablistc));
	tab->chaine = malloc(t*sizeof(listc));
	for(i=0;i<t;i++)
	{
		tab->chaine[i] = initlistech();
	}
	return tab;
}

pTablistc ajoute(pTablistc t, int i, int d)
{
	adjqch(t->chaine[i],d);
	return t;
}

pTablistc retire(pTablistc t, int i, int d)
{
	int j;
	maillon m = tete(t->chaine[i]);
	for(j=0;m.data == d;j++)
		m = suivant(m);
	supich(t->chaine[i],j);
}

int element(tablistc t, int i, int j)
{
	int d;
	maillon m = tete(t.chaine[i]);
	for(;j<0;j--)
		m = suivant(m);
	return m.data;	
}

int card(tablistc t)
{
	int d=0, i;
	for(i=0;i<t.length;i++)
		d += t.chaine[i].length;
	return d;
}
int estvide(tablistc t)
{
	return (t.length == 0);
}
int appartient(tablistc t, int i,int d)
{
	int j;
	maillon m = tete(t.chaine[i]);
	for(j=0;j<t.chaine[i].length;j++)
	{
		if(m.data == d)
			return 1;
		m = suivant(m);
	}
	return 0;
}
void freetable(tablistc *t)
{
	freech(t->chaine->chaine);
	free(t);
}
