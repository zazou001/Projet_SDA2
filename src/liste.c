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
void* adjq(void *liste, int type, ...)
{
	va_list vl;
	va_start(vl,type);
	switch(type)
	{
		case 3:
			((ListPoints*)liste)->ldata[((ListPoints*)liste)->length].x = va_arg(vl,double);
			((ListPoints*)liste)->ldata[((ListPoints*)liste)->length].y = va_arg(vl,double);
			((ListPoints*)liste)->ldata[((ListPoints*)liste)->length].z = va_arg(vl,double);
			((ListPoints*)liste)->length += 1;
			break;
		case 2:
			((ListFaces*)liste)->ldata[((ListFaces*)liste)->length].idebut = va_arg(vl,unsigned int);
			((ListFaces*)liste)->ldata[((ListFaces*)liste)->length].nbrearete = va_arg(vl,unsigned int);
			((ListFaces*)liste)->length += 1;
			break;
		case 1:
			((ListArete*)liste)->ldata[((ListArete*)liste)->length] = va_arg(vl,unsigned int);
			((ListArete*)liste)->length += 1;
			break;
	}
	va_end(vl);
	return liste;
}
void* adjt(void *liste, int type, ...)
{
	int j;
	va_list vl;
	va_start(vl,type);
		switch(type)
	{
		case 3:
			((ListPoints*)liste)->length +=1;
			for(j=((ListPoints*)liste)->length;j>=0;j--)
				((ListPoints*)liste)->ldata[j] = ((ListPoints*)liste)->ldata[j-1];
			((ListPoints*)liste)->ldata[0].x = va_arg(vl,double);
			((ListPoints*)liste)->ldata[0].y = va_arg(vl,double);
			((ListPoints*)liste)->ldata[0].z = va_arg(vl,double);
			break;
		case 2:
			((ListFaces*)liste)->length +=1;
			for(j=((ListFaces*)liste)->length;j>=0;j--)
				((ListFaces*)liste)->ldata[j] = ((ListFaces*)liste)->ldata[j-1];
			((ListFaces*)liste)->ldata[0].idebut = va_arg(vl,unsigned int);
			((ListFaces*)liste)->ldata[0].nbrearete = va_arg(vl,unsigned int);
			break;
		case 1:
			((ListArete*)liste)->length +=1;
			for(j=((ListArete*)liste)->length;j>=0;j--)
				((ListArete*)liste)->ldata[j] = ((ListArete*)liste)->ldata[j-1];
			((ListArete*)liste)->ldata[0] = va_arg(vl,unsigned int);
			break;
	}
	return liste;
}
void* adji(unsigned int i,void *liste,  int type,...)
{
	va_list vl;
	va_start(vl,type);
	int j;
		switch(type)
	{
		case 3:
			((ListPoints*)liste)->length +=1;
			for(j=((ListPoints*)liste)->length;j>=i;j--)
				((ListPoints*)liste)->ldata[j] = ((ListPoints*)liste)->ldata[j-1];
			((ListPoints*)liste)->ldata[i].x = va_arg(vl,double);
			((ListPoints*)liste)->ldata[i].y = va_arg(vl,double);
			((ListPoints*)liste)->ldata[i].z = va_arg(vl,double);
			break;
		case 2:
			((ListFaces*)liste)->length +=1;
			for(j=((ListFaces*)liste)->length;j>=i;j--)
				((ListFaces*)liste)->ldata[j] = ((ListFaces*)liste)->ldata[j-1];
			((ListFaces*)liste)->ldata[i].idebut = va_arg(vl,unsigned int);
			((ListFaces*)liste)->ldata[i].nbrearete = va_arg(vl,unsigned int);
			break;
		case 1:
			((ListArete*)liste)->length +=1;
			for(j=((ListArete*)liste)->length;j>=i;j--)
				((ListArete*)liste)->ldata[j] = ((ListArete*)liste)->ldata[j-1];
			((ListArete*)liste)->ldata[i] = va_arg(vl,unsigned int);
			break;
	}
	return liste;
}
void* supq(int type, void *liste)
{
	switch(type)
	{
		case 3:
			((ListPoints*)liste)->length -= 1;
			break;
		case 2:
			((ListFaces*)liste)->length -= 1;
			break;
		case 1:
			((ListArete*)liste)->length -= 1;
			break;
	}
}
void* supt(int type, void *liste)
{
	int i;
	switch(type)
	{
		case 3:
			for(i=0;i<((ListPoints*)liste)->length;i++)
				((ListPoints*)liste)->ldata[i] = ((ListPoints*)liste)->ldata[i+1];
			((ListPoints*)liste)->length -=1;
			break;
		case 2:
			for(i=0;i<((ListFaces*)liste)->length;i++)
				((ListFaces*)liste)->ldata[i] = ((ListFaces*)liste)->ldata[i+1];
			((ListFaces*)liste)->length -=1;
			break;
		case 1:
			for(i=0;i<((ListArete*)liste)->length;i++)
				((ListArete*)liste)->ldata[i] = ((ListArete*)liste)->ldata[i+1];
			((ListArete*)liste)->length -=1;
			break;
	}
	return liste;
}
void* supi(int type, void *liste, unsigned int i)
{
	switch(type)
	{
		case 3:
			for(;i<((ListPoints*)liste)->length;i++)
				((ListPoints*)liste)->ldata[i] = ((ListPoints*)liste)->ldata[i+1];
			((ListPoints*)liste)->length -=1;
			break;
		case 2:
			for(;i<((ListFaces*)liste)->length;i++)
				((ListFaces*)liste)->ldata[i] = ((ListFaces*)liste)->ldata[i+1];
			((ListFaces*)liste)->length -=1;
			break;
		case 1:
			for(;i<((ListArete*)liste)->length;i++)
				((ListArete*)liste)->ldata[i] = ((ListArete*)liste)->ldata[i+1];
			((ListArete*)liste)->length -=1;
			break;
	}
	return liste;
}
int longueur(int type, void *liste)
{
	switch(type)
	{
		case 3:
			return ((ListPoints*)liste)->length;
			break;
		case 2:
			return ((ListFaces*)liste)->length;
			break;
		case 1:
			return ((ListArete*)liste)->length;
			break;
	}
}

void freeliste(int type, void *liste){
		switch(type)
	{
		case 3:
			free(((ListPoints*)liste)->ldata);
			free(((ListPoints*)liste));
			break;
		case 2:
			free(((ListFaces*)liste)->ldata);
			free(((ListFaces*)liste));
			break;
		case 1:
			free(((ListArete*)liste)->ldata);
			free(((ListArete*)liste));
			break;
	}

}
