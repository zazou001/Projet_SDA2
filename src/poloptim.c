#include "poloptim.h"

poloptim convertir(polyedre p)
{
	int i, j;
	//ListInt liste;
	poloptim *o =malloc(sizeof(poloptim));
	o->S = p.S;
	o->A = p.A;
	o->F = p.F;
	o->sa = initable(p.S->length);
	o->fi = initable(p.F->length);
	for(i=0;i<=p.S->length;i++)
	{/*
		ListInt liste = FaceIncidentes(p,i);
		for(j=0;j<liste.length;j++)
		{
			//ajoute(o->sa,i,liste.ldata[j]);
		}
		freeliste(1,(&liste));*/
	}
	/*
	for(i=0;i<=p.F->length;i++)
	{
		liste = FaceConnectees(p,i);
		for(j=0;j<liste.length;j++)
		{
			ajoute(*(o->fi),i,liste.ldata[j]);
		}
	}*/
	return *o;
}
int NbSommetoptim(poloptim p)
{
	return longueur(3,&(p.S));
}
int NbFaceoptim(poloptim p)
{
	return longueur(2,&p.F);
}
sommet GetSommetoptim(poloptim p,int i)
{
	return p.S->ldata[i-1];
}
int NbSommetFaceoptim(poloptim p, int i)
{
	return p.F->ldata[i-1].nbrearete;
}
int SommetFaceoptim(poloptim p,int i, int j)
{
	if(NbSommetFaceoptim(p,i)<(j))
		exit(EXIT_FAILURE);
	return p.A->ldata[p.F->ldata[i-1].idebut+j-1];
}

ListInt FaceIncidentesoptim(poloptim p, int i)
{
	ListInt *l = malloc(sizeof(ListInt));
	l->length = 0;
	l->ldata = malloc(p.sa[i].length*sizeof(int));
	maillon m = tete(*(p.sa[i].chaine));
	int t;
	for(t=0;t<p.sa[i].length;t++)
	{
		adjq(l,1,m.data);
		m = suivant(m);
	}
	return *l;
}
ListInt FaceAdjacentesoptim(poloptim p, int i);
ListInt FaceConnecteesoptim(poloptim p, int i)
{
	ListInt *l = malloc(sizeof(ListInt));
	l->length = 0;
	l->ldata = malloc(p.fi[i].length*sizeof(int));
	maillon m = tete(*(p.fi[i].chaine));
	int t;
	for(t=0;t<p.fi[i].length;t++)
	{
		adjq(l,1,m.data);
		m = suivant(m);
	}
	return *l;
}
int Connexeoptim(poloptim p, poloptim cc[]);
