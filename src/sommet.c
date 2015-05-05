#include "sommet.h"

pSommet point(float x, float y, float z)
{
	pSommet s = malloc(sizeof(sommet));
	s->x = x; s->y = y; s->z = z;
	return s;
}
pFace cote(unsigned int idebut, unsigned int nbrearete)
{
	pFace f = malloc(sizeof(face));
	f->idebut = idebut; f->nbrearete = nbrearete;
	return f;
}
