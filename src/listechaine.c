#include "listechaine.h"

listc initlistech()
{
	listc *c = malloc(sizeof(listc));
	c->length = 0;
	c->data = NULL;
	return c;
}

listc adjqch(listc liste, ...)
{
	va_list vl;
	va_start(vl,type);
	
	va_end(vl);
}
/*listc adjtch(listc liste, ...)
{
	va_list vl;
	va_start(vl,type);
	
	va_end(vl);
}
listc adjich(unsigned int i, listc liste,...)
{
	va_list vl;
	va_start(vl,type);
	
	va_end(vl);
}
/*listc supqch(listc liste);
listc suptch(listc liste);
listc supich(listc liste, unsigned int i);
void * tete(char type, listc liste);
void * suivant(char type, void *data);
int est_vide(char type, listc liste);
int longueurch(char type, listc liste);
void freeoptim(char type, listc liste);*/
