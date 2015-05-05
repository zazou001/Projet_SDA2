#include "liste.h"

pPolyedre initliste(unsigned int nbrepoint, unsigned int nbreface, unsigned int nbrearete)
{
	pPolyedre P = malloc(sizeof(polyedre));
	P->S = malloc(sizeof(ListPoints));
	P->F = malloc(sizeof(ListFaces));
	P->A = malloc(sizeof(ListArete));
	P->S->ldata = malloc(sizeof(sommet) *nbrepoint);
	P->F->ldata = malloc(sizeof(face) *nbreface);
	P->A->ldata = malloc(sizeof(arete) *nbrearete);
	P->S->length = 0;
	P->F->length = 0;
	P->A->length = 0;
	return P;
}
pPolyedre adjq(pPolyedre poly, int type, ...)
{
	va_list vl;
	va_start(vl,type);
	switch(type)
	{
		case 3:
			poly->S->ldata[poly->S->length].x = va_arg(vl,double);
			poly->S->ldata[poly->S->length].y = va_arg(vl,double);
			poly->S->ldata[poly->S->length].z = va_arg(vl,double);
			poly->S->length += 1;
			break;
		case 2:
			poly->F->ldata[poly->F->length].idebut = va_arg(vl,unsigned int);
			poly->F->ldata[poly->F->length].nbrearete = va_arg(vl,unsigned int);
			poly->F->length += 1;
			break;
		case 1:
			poly->A->ldata[poly->A->length] = va_arg(vl,unsigned int);
			poly->A->length += 1;
			break;
	}
	va_end(vl);
	return poly;
}
pPolyedre adjt(pPolyedre poly, int type, ...)
{
	return poly;
}
pPolyedre adji(unsigned int i,pPolyedre poly,  int type,...)
{
	return poly;
}
pPolyedre supq(int type, pPolyedre poly)
{
	switch(type)
	{
		case 3:
			poly->S->length -= 1;
			break;
		case 2:
			poly->F->length -= 1;
			break;
		case 1:
			poly->A->length -= 1;
			break;
	}
}
pPolyedre supt(int type, pPolyedre poly)
{
	return poly;
}
pPolyedre supi(int type, pPolyedre poly, unsigned int i)
{
	return poly;
}
int longueur(int type, pPolyedre poly)
{
	switch(type)
	{
		case 3:
			return poly->S->length;
			break;
		case 2:
			return poly->F->length;
			break;
		case 1:
			return poly->A->length;
			break;
	}
}
void printlist(int type, pPolyedre poly)
{
	unsigned int i;
	switch(type)
	{
		case 3:
			for(i=0;i<poly->S->length;i++)
			{
				printf("[%lf,%lf,%lf]\n",
				poly->S->ldata[i].x,poly->S->ldata[i].y,poly->S->ldata[i].z);
			}
			break;
		case 2:
			for(i=0;i<poly->F->length;i++)
			{
				printf("[%u,%u]\n",
				poly->F->ldata[i].idebut,poly->F->ldata[i].nbrearete);
			}
			break;
		case 1:
			for(i=0;i<poly->F->length;i++)
			{
				printf("[%u]\n",poly->A->ldata[i]);
			}
			break;
	}
}
void freeliste(pPolyedre poly){
	free(poly->S->ldata);
	free(poly->F->ldata);
	free(poly->A->ldata);
	free(poly->S);
	free(poly->F);
	free(poly->A);
	free(poly);
}
