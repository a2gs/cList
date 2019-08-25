#ifndef __CLIST_LIB_H__
#define __CLIST_LIB_H__

#define CLIST_ERRO	(0)
#define CLIST_OK     (1)
#define CLIST_FULL	(0)
#define CLIST_EMPTY  (1)
#define CLIST_SOME   (2)

typedef struct _clist_t{
	unsigned int qtd;
	unsigned int size;
	unsigned int head;
	unsigned int tail;
	void *buffer;
}clist_t;

int clist_create(clist_t *list, void *buf, unsigned int sz);
int clist_put(clist_t *list, void *node);
void * clist_get(clist_t *list);
void * clist_peek(clist_t *list);
unsigned int clist_size(clist_t *list);
unsigned int clist_qtd(clist_t *list);
int clist_isfull(clist_t *list);

#endif
