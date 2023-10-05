#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../../linked_list/linked_list.h"

struct LinkedList * MergeSortedList(struct LinkedList *list1,struct LinkedList *list2);

int main(void)
{
    struct LinkedList *list1 = InitializeList();
    struct LinkedList *list2 = InitializeList();
    struct LinkedList *list3 = NULL;
    assert(list1 != NULL);
    assert(list2 != NULL);
    assert(InsertAtEnd(list1,1) == 0);
    assert(InsertAtEnd(list1,20) == 0);
    assert(InsertAtEnd(list1,30) == 0);
    DisplayData(list1);
    assert(InsertAtEnd(list2,1) == 0);
    assert(InsertAtEnd(list2,2) == 0);
    assert(InsertAtEnd(list2,3) == 0);
    assert(InsertAtEnd(list2,89) == 0);
    DisplayData(list2);
    list3 = MergeSortedList(list1,list2);
    DisplayData(list3);
    return 0;
}

struct LinkedList * MergeSortedList(struct LinkedList *list1,struct LinkedList *list2)
{
    struct LinkedList *merged = NULL;
    if((list1 != NULL) && (list2 != NULL))
    {
        merged = InitializeList(); 
        if(merged != NULL)
        {
            struct Node *temp1 = list1->head;
            struct Node *temp2 = list2->head;
            while((temp1 !=NULL) && (temp2 != NULL))
            {
                if(temp1->data < temp2->data)
                {
                    InsertAtEnd(merged,temp1->data);
                    temp1 = temp1->ptr;
                }
                else
                {
                    InsertAtEnd(merged,temp2->data);
                    temp2 = temp2->ptr;
                }
            }
            while(temp1 !=NULL)
            {
                InsertAtEnd(merged,temp1->data);
                temp1 = temp1->ptr;
            }
            while(temp2 !=NULL)
            {
                InsertAtEnd(merged,temp2->data);
                temp2 = temp2->ptr;
            }
        }
    }
    return merged;
}