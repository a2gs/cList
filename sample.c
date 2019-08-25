#include <stdio.h>

#include "clist.h"

#define CIRCULAR_LIST_SIZE  (100)

int main(int argc, char *argv[])
{
	clist_t cListCtrl;
	float buffer[CIRCULAR_LIST_SIZE];

	if(clist_create(&cListCtrl, buffer, CIRCULAR_LIST_SIZE) == CLIST_ERRO){
	}


	return(0);
}
