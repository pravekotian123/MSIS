#ifndef SORT_LINKED_LIST_INCLUDED
#define SORT_LINKED_LIST_INCLUDED
#include <stdint.h>

struct Node *SwapNodes(struct Node *node1,struct Node *node2);
int BubbleSort(struct List *list,uint16_t offset,uint16_t size);

#endif