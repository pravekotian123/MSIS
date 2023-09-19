#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

int PeekData(struct LinkedList * my_list);
int IsStackEmpty(struct LinkedList * my_list);


int main(void)
{
    struct LinkedList *stack_ptr = InitializeList();
    assert(stack_ptr != NULL);
    assert(InsertAtEnd(stack_ptr,1) == 0);
    assert(InsertAtEnd(stack_ptr,2) == 0);
    assert(InsertAtEnd(stack_ptr,3) == 0);
    assert(DeleteAtEnd(stack_ptr) == 0);
    assert(InsertAtEnd(stack_ptr,4) == 0);
    if(IsStackEmpty(stack_ptr) == 0)
    {
        printf("peeked data = %d\n",PeekData(stack_ptr));
    }
    assert(InsertAtEnd(stack_ptr,5) == 0);
    if(IsStackEmpty(stack_ptr) == 0)
    {
        printf("peeked data = %d\n",PeekData(stack_ptr));
    }
    DisplayData(stack_ptr);
    
    return 0;
}

int PeekData(struct LinkedList * my_list)
{
    int return_value  = -1;
    if(my_list != NULL)
    {
        struct Node *temp_node = my_list->head;
        if(temp_node != NULL)
        {
            while(temp_node->ptr != NULL)
            {
                temp_node = temp_node->ptr;
            }
            return_value = temp_node->data;
        }
    }
    return return_value;
}

int IsStackEmpty(struct LinkedList * my_list)
{
    int return_value  = -1;
    if(my_list->head != NULL)
    {
        return_value = 0;
    }
    return return_value;
}