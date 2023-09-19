#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

int main(void)
{
    struct LinkedList *queue_ptr = InitializeList();
    assert(queue_ptr != NULL);
    assert(InsertAtEnd(queue_ptr,1) == 0);
    assert(InsertAtEnd(queue_ptr,2) == 0);
    assert(InsertAtEnd(queue_ptr,3) == 0);
    assert(InsertAtEnd(queue_ptr,4) == 0);
    assert(DeleteAtBegining(queue_ptr) == 0);
    assert(InsertAtEnd(queue_ptr,5) == 0);
    DisplayData(queue_ptr);
    return 0;
}

