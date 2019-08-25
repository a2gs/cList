/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 * cList
 * Circular list/buffer.
 *
 * MIT License
 */

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
	size_t dataSize;
	void *buffer;
}clist_t;

/* int clist_create(clist_t *list, void *buf, unsigned int sz, size_t dataSize)
 *
 * Starts a circlar list context.
 * Input:
 *  list - context
 *  buf - Buffer/array to store nodes
 *  sz - Max circular list
 *  dataSize - Size of one node (sizeof(buf[0]))
 * Output:
 *  CLIST_OK
 */
int clist_create(clist_t *list, void *buf, unsigned int sz, size_t dataSize);

/* int clist_put(clist_t *list, void *node)
 *
 * Inserts one node.
 * Input:
 *  list - context
 *  node - node to insert (memcpy())
 *  copyNode - function to copy node (user knows how to copy your data: '=' or memcpy())
 * Output:
 *  CLIST_OK
 *  CLIST_FULL
 */
/*
int clist_put(clist_t *list, void *node);
*/
int clist_put(clist_t *list, void *node, void (*copyNode)(void *dst, void *src));

/* int clist_get(clist_t *list, void **node)
 *
 * Return (and remove) a node (tail) from list.
 * Input:
 *  list - context
 *  *node - Pointer to node
 * Output:
 *  CLIST_OK
 *  CLIST_EMPTY
 */
int clist_get(clist_t *list, void *node, void (*copyNode)(void *dst, void *src));

/* int clist_peek(clist_t *list)
 *
 * Return(and not remove) a node (tail) from list.
 * Input:
 *  list - context
 *  *node - Pointer to node
 * Output:
 *  CLIST_OK
 *  CLIST_EMPTY
 */
int clist_peek(clist_t *list, void **node);

/* unsigned int clist_size(clist_t *list)
 *
 * Return the max size from a list.
 * Input:
 *  list - context
 * Output:
 *  Max size
 */
unsigned int clist_size(clist_t *list);

/* unsigned int clist_qtd(clist_t *list)
 *
 * Return node quantity used from a list.
 * Input:
 *  list - context
 * Output:
 *  Qtd nodes
 */
unsigned int clist_qtd(clist_t *list);

/* int clist_isfull(clist_t *list)
 *
 * Return list state: EMPTY, SOME NODES, FULL
 * Input:
 *  list - context
 * Output:
 *  CLIST_FULL
 *  CLIST_EMPTY
 *  CLIST_SOME
 */
int clist_isfull(clist_t *list);

/* int clist_clear(clist_t *list)
 *
 * Empty a list.
 * Input:
 *  list - context
 * Output:
 *  CLIST_OK
 */
int clist_clear(clist_t *list);

#endif
