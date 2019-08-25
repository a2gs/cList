#include "clist.h"

int clist_create(clist_t *list, void *buf, unsigned int sz)
{
	list->head = 0;
	list->tail = 0;
	list->size = 0;
	list->qtd  = 0;
	list->buffer = buf;

	return(CLIST_OK);
}

int clist_put(clist_t *list, void *node)
{
	if(clist_isfull(list) == CLIST_FULL)
		return(CLIST_ERRO); /* buffer full */

	list->buffer[list->head] = node;

	list->head = (list->head + 1) % list->size;

	return(CLIST_OK);
}

void * clist_get(clist_t *list)
{
	void *ret = NULL;

	if(clist_isfull(list) == CLIST_EMPTY)
		return(ret); /* buffer empty */

	ret = list->buffer[list->tail];

	list->tail = (list->tail + 1) % list->size;

	return(ret);
}

void * clist_peek(clist_t *list)
{
	return(list->buffer[list->head]);
}

unsigned int clist_size(clist_t *list)
{
	return(list->size);
}

unsigned int clist_qtd(clist_t *list)
{
	return(list->qtd);
}

int clist_isfull(clist_t *list)
{
	if(list->qtd == list->size) return(CLIST_FULL);
	else if(list->qtd == 0)     return(CLIST_EMPTY);

	return(CLIST_SOME);
}
