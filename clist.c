/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 * cList
 * Circular list/buffer.
 *
 * MIT License
 */

#include <string.h>
#include "clist.h"

int clist_create(clist_t *list, void *buf, unsigned int sz, size_t dataSize)
{
	list->head = 0;
	list->tail = 0;
	list->qtd  = 0;
	list->size = sz;
	list->dataSize = dataSize;
	list->buffer = buf;

	return(CLIST_OK);
}

int clist_clear(clist_t *list)
{
	list->head = 0;
	list->tail = 0;
	list->qtd  = 0;

	return(CLIST_OK);
}

int clist_put(clist_t *list, void *node, void (*copyNode)(void *dst, void *src))
{
	if(clist_isfull(list) == CLIST_FULL)
		return(CLIST_FULL); /* buffer full */

	/*
	memcpy(list->buffer + list->head * list->dataSize, (const void *)node, list->dataSize);
	*/
	copyNode(list->buffer + list->head * list->dataSize, node);

	list->head = (list->head + 1) % list->size;
	list->qtd++;

	return(CLIST_OK);
}

int clist_get(clist_t *list, void **node)
{
	if(clist_isfull(list) == CLIST_EMPTY)
		return(CLIST_EMPTY); /* buffer empty */

	*node = list->buffer + list->tail * list->dataSize;

	list->tail = (list->tail + 1) % list->size;
	list->qtd--;

	return(CLIST_OK);
}

int clist_peek(clist_t *list, void **node)
{
	if(clist_isfull(list) == CLIST_EMPTY)
		return(CLIST_EMPTY); /* buffer empty */

	*node = list->buffer + list->tail * list->dataSize;

	return(CLIST_OK);
}

unsigned int clist_size(clist_t *list)
{
	return(CLIST_OK);
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
