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
		node += i + 1;
	}

	printf("List is: [%d] (2=full, 3=empty, 4=some) | Qtd: [%u] | Size: [%u]\n", clist_isfull(&cListCtrl), clist_qtd(&cListCtrl), clist_size(&cListCtrl));

	if(clist_peekTail(&cListCtrl, &node, copyNode) != CLIST_OK){
		printf("Erro clist_peekTail()\n");
		return(3);
	}
	printf("clist tail node: [%f]\n", node);

	if(clist_peekHead(&cListCtrl, &node, copyNode) != CLIST_OK){
		printf("Erro clist_peekHead()\n");
		return(4);
	}
	printf("clist head node: [%f]\n", node);

	for(i = 0; clist_get(&cListCtrl, &node, copyNode) != CLIST_EMPTY; i++){
		printf("GET: [%f] (i=[%d])\n", node, i);
	}

	return(0);
}
