#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../linked_list/list.h"
struct Student
{
    char name[20];
    int roll_number;
};
int main(void) {
    int arr[4] = {1,2,3,4};
    printf("Hello dude \n");
    struct List *test_list = InitializeList();
    struct List *student_list = InitializeList();
    assert(test_list != NULL);
    assert(student_list != NULL);
    assert(InsertAtBegining(test_list,&arr[0],sizeof(int)) == 0);
    assert(InsertAtBegining(test_list,&arr[1],sizeof(int)) == 0);
    assert(InsertAtEnd(test_list,&arr[2],sizeof(int)) == 0);
    assert(InsertAtPosition(test_list,&arr[3],sizeof(int),3) == 0);
    for(int i=0;i <4 ;i++)
        printf("%d \n",*((int *)FetchDataByPosition(test_list,i)));

    assert(InsertAtBegining(student_list,&((struct Student){"Paqueta",21}),sizeof(struct Student)) == 0);
    assert(InsertAtEnd(student_list,&((struct Student){"Hope",10}),sizeof(struct Student)) == 0);
    assert(InsertAtBegining(student_list,&((struct Student){"Zaha",10}),sizeof(struct Student)) == 0);
    assert(InsertAtPosition(student_list,&((struct Student){"Awoniyi",10}),sizeof(struct Student),1) == 0);
    for(int i=0;i <4 ;i++)
        printf("Name = %s, Roll Number = %d \n",((struct Student *)FetchDataByPosition(student_list,i))->name,((struct Student *)FetchDataByPosition(student_list,i))->roll_number);
    return 0;
}