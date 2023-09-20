#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../sorting/sort.h"


int main(void)
{
    printf("hi\n");
    int arr[5] = {9,0,2,6,3};
    InsertionSort(arr,5);
    for(int i=0;i<5;i++)
        printf("%d ,",arr[i]);
    printf("\n");
    return 0;
}
