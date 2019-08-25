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
	float buffer[CIRCULAR_LIST_SIZE] = {0.0};
	float node;
	int i;

	if(clist_create(&cListCtrl, buffer, CIRCULAR_LIST_SIZE, sizeof(float)) == CLIST_ERRO){
		printf("Error clist_create()\n");
		return(1);
	}

	node = 13.8;

	for(i = 0; i < 20; i++){
		if(clist_put(&cListCtrl, &node, copyNode) != CLIST_OK){
			printf("Error clist_put() [%d]\n", i);
			return(2);
		}
		printf("PUT: [%f] (i=[%d])\n", node, i);
		node += i;
	}

	if(clist_peek(&cListCtrl, &node, copyNode) != CLIST_OK){
		printf("Erro clist_peek()\n");
		return(3);
	}
	printf("clist head node: [%f]\n", node);

	for(i = 0; clist_get(&cListCtrl, &node, copyNode) != CLIST_EMPTY; i++){
		printf("GET: [%f] (i=[%d])\n", node, i);
	}

	return(0);
}
