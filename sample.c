/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 * cList
 * Circular list / buffer. Usage sample.
 *
 * MIT License
 *
 */

#include <stdio.h>

#include "clist.h"

#define CIRCULAR_LIST_SIZE  (100)

void copyNode(void *a, void *b)
{
	*((float *)a) = *((float *)b);
	return;
}

int main(int argc, char *argv[])
{
	clist_t cListCtrl;
	float buffer[CIRCULAR_LIST_SIZE];
	float node;

	if(clist_create(&cListCtrl, buffer, CIRCULAR_LIST_SIZE, sizeof(float)) == CLIST_ERRO){
	}

	node = 13.8;

	clist_put(&cListCtrl, &node, copyNode);


	return(0);
}
