#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"
int main(void)
{
    struct LinkedList *list_ptr = InitializeList();
    struct LinkedList *list_ptr1 = InitializeList();
    assert(list_ptr != NULL);
    assert(list_ptr1 != NULL);
    assert(InsertAtEnd(list_ptr,8) == 0);
    assert(InsertAtEnd(list_ptr1,20) == 0);
    assert(InsertAtEnd(list_ptr,30) == 0);
    DisplayData(list_ptr);
    //assert(InsertAtEnd(list_ptr1,25) == 0);
    assert(InsertAtBegining(list_ptr,12) == 0);
    assert(InsertAtBegining(list_ptr,10) == 0);
    assert(InsertAfterData(list_ptr,12,5) == 0);
    DisplayData(list_ptr);
    assert(InsertAtPosition(list_ptr,2,0) == 0);
    DisplayData(list_ptr);
    assert(InsertAtPosition(list_ptr,15,2) == 0);
    DisplayData(list_ptr);
    assert(DeleteAtBegining(list_ptr) == 0);
    assert(DeleteAtEnd(list_ptr) == 0);
    DisplayData(list_ptr);
    assert(DeleteData(list_ptr,5) == 0);
    DisplayData(list_ptr);
    DisplayData(list_ptr1);
    assert(MergeList(list_ptr,list_ptr1) == 0);
    DisplayData(list_ptr);
    return 0;
}