/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 * cList
 * Circular list/buffer.
 *
 * MIT License
 *
 */

#include <string.h>
#include "clist.h"

int clist_create(clist_t *list, void *buf, unsigned int sz, size_t dataSize)
{
	list->head = 0;
	list->tail = 0;
	list->size = 0;
	list->qtd  = 0;
	list->dataSize = dataSize;
	list->buffer = buf;

	return(CLIST_OK);
}

int clist_put(clist_t *list, void *node)
{
	if(clist_isfull(list) == CLIST_FULL)
		return(CLIST_ERRO); /* buffer full */

	memcpy(list->buffer + list->head * list->dataSize, (const void *)node, list->dataSize);

	list->head = (list->head + 1) % list->size;

	return(CLIST_OK);
}

void * clist_get(clist_t *list)
{
	void *ret = (void *)0;

	if(clist_isfull(list) == CLIST_EMPTY)
		return(ret); /* buffer empty */

	ret = list->buffer + list->tail * list->dataSize;

	list->tail = (list->tail + 1) % list->size;

	return(ret);
}

void * clist_peek(clist_t *list)
{
	return(list->buffer + (list->tail * list->dataSize));
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
