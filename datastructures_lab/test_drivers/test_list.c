#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "../linked_list/list.h"
#include "../linked_list/sort_linked_list.h"
struct Student
{
    char name[20];
    char destination[20];
    int roll_number;
};
int main(void) {
    int arr[5] = {1,2,3,4,6};
    printf("Hello dude \n");
    struct List *test_list = InitializeList();
    struct List *student_list = InitializeList();
    assert(test_list != NULL);
    assert(student_list != NULL);
    assert(INSERT_AT_BEGINING(test_list,&arr[3]) == 0);
    assert(INSERT_AT_END(test_list,&arr[2]) == 0);
    assert(INSERT_AT_END(test_list,&arr[1]) == 0);
    assert(INSERT_AT_END(test_list,&arr[0]) == 0);
    printf("Before sorting\n");
    for(int i=0;i < 4;i++)
    {
        printf("%d \n",*((int *)FetchDataByPosition(test_list,i)));
    }
    //test_list->head = SwapNodes(test_list->head,test_list->head->ptr);
    BubbleSort(test_list,0,sizeof(int));
    printf("After sorting\n");
    for(int i=0;i < 4;i++)
    {
        printf("%d \n",*((int *)FetchDataByPosition(test_list,i)));
    }
    assert(INSERT_AT_BEGINING(student_list,&((struct Student){"Paqueta","doctor",21})) == 0);
    assert(INSERT_AT_END(student_list,&((struct Student){"Hope","engg",10})) == 0);
    assert(INSERT_AT_BEGINING(student_list,&((struct Student){"Zaha","doctor",10})) == 0);
    assert(INSERT_AT_POSITION(student_list,&((struct Student){"Awoniyi","teacher",10}),1) == 0);
    BubbleSort(test_list,0,sizeof(int));
    for(int i=0;i < 4;i++)
        printf("Name = %s, Designation = %s, Roll Number = %d \n",((struct Student *)FetchDataByPosition(student_list,i))->name,((struct Student *)FetchDataByPosition(student_list,i))->destination,((struct Student *)FetchDataByPosition(student_list,i))->roll_number);
    return 0;
}