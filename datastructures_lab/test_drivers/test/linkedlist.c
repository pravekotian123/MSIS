#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "linkedlist.h"

struct Node *GetNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(node != NULL)
    {
        node->data = data;
        node->link =  NULL;
    }
    return node;
}
struct List *InitializeList(void)
{
    struct List *list = (struct List *)malloc(sizeof(struct List));
    if(list != NULL)
    {
        list->head = NULL;
    }
    return list;
}

int InsertAtBegining(struct List *list,int data)
{
    int return_val  = -1;
    if(list != NULL)
    {
        if(list->head == NULL)
        {
            list->head = GetNode(data);
            return_val = 0;
        }
        else{
            struct Node * temp =  GetNode(data);
            if(temp != NULL)
            {
                temp->link = list->head;
                list->head = temp;
                return_val = 0;
            }
        }
    }
    return return_val;
}

int InsertInSortingOrder(struct List *list,int data)
{
    if(list != NULL)
    {
        struct Node **temp = &(list->head);
        while(*temp != NULL)
        {
            if((*temp)->data > data)
            {
                struct Node *new = GetNode(data);
                new->link  = *temp;
                *temp = new;
                break;
            }
            temp = &((*temp)->link);
        }
        if((*temp == NULL))
        *temp = GetNode(data);
    }
}

void PrintList(struct List *list)
{
    if(list != NULL)
    {
        struct Node *temp =list->head;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp= temp->link;
        }
    }
}


int main(void)
{
    struct List *list=InitializeList();
    //InsertAtBegining(list,3);
    //InsertAtBegining(list,2);
    InsertInSortingOrder(list,1);
    InsertInSortingOrder(list,2);
    InsertInSortingOrder(list,3);
    InsertInSortingOrder(list,4);
    InsertInSortingOrder(list,5);
    PrintList(list);
}