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
    assert(INSERT_AT_BEGINING(test_list,&arr[0]) == 0);
    assert(INSERT_AT_BEGINING(test_list,&arr[1]) == 0);
    assert(INSERT_AT_END(test_list,&arr[2]) == 0);
    assert(INSERT_AT_POSITION(test_list,&arr[3],3) == 0);
  //  assert(DELETE_AT_BEGINING(test_list) == 0);
   // assert(DELETE_AT_END(test_list) == 0);
    for(int i=0;i < 4;i++)
    {
        printf("%d \n",*((int *)FetchDataByPosition(test_list,i)));
    }
    assert(INSERT_AT_BEGINING(student_list,&((struct Student){"Paqueta",21})) == 0);
    assert(INSERT_AT_END(student_list,&((struct Student){"Hope",10})) == 0);
    assert(INSERT_AT_BEGINING(student_list,&((struct Student){"Zaha",10})) == 0);
    assert(INSERT_AT_POSITION(student_list,&((struct Student){"Awoniyi",10}),1) == 0);
   // assert(DELETE_AT_BEGINING(student_list) == 0);
   // assert(DELETE_AT_END(student_list) == 0);
    for(int i=0;i < 4;i++)
        printf("Name = %s, Roll Number = %d \n",((struct Student *)FetchDataByPosition(student_list,i))->name,((struct Student *)FetchDataByPosition(student_list,i))->roll_number);
    return 0;
}