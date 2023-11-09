#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

struct Node *SwapNodes(struct Node *node1,struct Node *node2)
{
    struct Node *ret_val = NULL;
    if((node1 != NULL) && (node2 != NULL))
    {
        struct Node *temp = node1;
        node1->ptr = node2->ptr;
        node2->ptr = temp;
        ret_val = node2;
    }
    return ret_val;
}

int BubbleSort(struct List *list,uint16_t offset,uint16_t size)
{
    if(list != NULL)
    {
        int size = 0;
        struct Node *temp = list->head;
        while(temp != NULL)
        {
            size++;
            temp = temp->ptr;
        }
        for(uint8_t i=0;i<size - 1;i++)
        {
            struct Node **base = &(list->head);
            temp = list->head;
            uint8_t k = 0;
            for(uint8_t j=0;j<size-i-1;j++)
            {
                struct Node *p1 = *base;
                struct Node *p2 = p1->ptr;
                /*provide optional library use option for future*/
                if(memcmp((uint8_t *)p1->data + offset,(uint8_t *)(p2->data)+offset,size) > 0)
                {        
                    *base =SwapNodes(p1,p2);
                }
                base = &((*base)->ptr);
            }
        }
    }
}