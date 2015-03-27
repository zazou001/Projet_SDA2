#ifndef SOMMET_H_
#define SOMMET_H

typedef struct{
	float coord[3];
}sommet, *pSommet;

typedef struct{
	signed int cote[2];
}face, *pFace;

typedef signed int arete;

#endif
