#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"
int main(void)
{
    struct LinkedList *list_ptr = InitializeList();
    assert(list_ptr != NULL);
    
    assert(InsertAtEnd(list_ptr,8) == 0);
    assert(InsertAtBegining(list_ptr,12) == 0);
    assert(InsertAtBegining(list_ptr,10) == 0);
    assert(InsertAfterData(list_ptr,12,5) == 0);
    DisplayData(list_ptr);
    assert(InsertAtPosition(list_ptr,2,0) == 0);
    DisplayData(list_ptr);
    assert(InsertAtPosition(list_ptr,15,2) == 0);
    DisplayData(list_ptr);
    return 0;
}