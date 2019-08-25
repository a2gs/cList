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
	int i;

	if(clist_create(&cListCtrl, buffer, CIRCULAR_LIST_SIZE, sizeof(float)) == CLIST_ERRO){
		printf("Error clist_create()\n");
		return(1);
	}

	node = 13.8;

	for(i = 0; i < 50; i++){
		if(clist_put(&cListCtrl, &node, copyNode) != CLIST_OK){
			printf("Error clist_put() %d\n", i);
			return(2);
		}
		printf("PUT: %f (i=%d)\n", node, i);
		node += i;
	}


	for(i = 0; i < 30; i++){
		if(clist_get(&cListCtrl, (void **)&node) != CLIST_OK){
			printf("Error clist_get() %d\n", i);
			return(2);
		}
		printf("GET: %f (i=%d)\n", node, i);

	}
	return(0);
}
