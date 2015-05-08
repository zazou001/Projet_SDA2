#include "listechaine.h"

listc initlistech()
{
	listc *c = malloc(sizeof(listc));
	c->length = 0;
	c->chaine = NULL;
	return *c;
}

listc adjqch(listc liste, int data,...)
{
	va_list vl;
	va_start(vl,data);
	pMaillon m = malloc(sizeof(maillon));
	pMaillon l = liste.chaine;
	while(l->s != NULL){l=l->s;}
	l->s = m;
	m->s = NULL;
	int r = va_arg(vl, int);
	m->data = r;
	liste.length +=1;
	while((r = va_arg(vl, int))!=NULL){adjqch(liste, r,NULL);}
	va_end(vl);
	return liste;
}

listc adjtch(listc liste, int data, ...)
{
	va_list vl;
	va_start(vl,data);
	pMaillon m = malloc(sizeof(maillon));
	m->s = liste.chaine;
	liste.chaine = m;
	int r = va_arg(vl, int);
	m->data = r;
	liste.length +=1;
	while((r = va_arg(vl, int))!=NULL){adjtch(liste, r,NULL);}
	va_end(vl);
	return liste;
}

listc adjich(unsigned int i, listc liste, int data, ...)
{
	va_list vl;
	va_start(vl,data);
	pMaillon m = malloc(sizeof(maillon));
	pMaillon l = liste.chaine;
	while(i > 0){l=l->s;i--;}
	m->s = l->s;
	l->s = m;
	int r = va_arg(vl, int);
	m->data = r;
	liste.length +=1;
	while((r = va_arg(vl, int))!=NULL){adjqch(liste, r,NULL);}
	va_end(vl);
	return liste;
}

listc supqch(listc liste)
{
	pMaillon q = liste.chaine;
	while(q->s->s != NULL){q = q->s;}
	free(q->s);
	q->s = NULL;
	return liste;
}

listc suptch(listc liste)
{
	pMaillon q = liste.chaine;
	liste.chaine = q->s;
	free(q);
	return liste;
}

listc supich(listc liste, unsigned int i)
{
	pMaillon q = liste.chaine, r;
	while(i > 1)
	{
		q = q->s;
		i--;
	}
	r = q;
	q = q->s;
	free(r);
	return liste;
}
	
maillon tete(listc liste)
{
	return *(liste.chaine);
}
maillon suivant(maillon m)
{
	return *(m.s);
}
int est_vide(listc liste)
{
	return (liste.length == 0);
}
int longueurch(listc liste)
{
	return liste.length;
}
void freech(pMaillon m)
{
	while(m->s)
		freech(m->s);
	free(m);
}
