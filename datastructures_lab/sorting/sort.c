
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void BubbleSort(int *array,int length)
{
    int sorted = 0;
    int iteration_count  =0;
    for(int i = 0;i < length;i++)
    {
        sorted = 0;
        iteration_count++;
        for(int j = 0;j < (length-i-1);j++)
        {
            if(array[j] > array[j+1])
            {
                int temp  = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                sorted = -1;
            }
        }
        if(sorted == 0)
        {
            break;
        }
       
    }
     printf("iteration count = %d\n",iteration_count);
}

void SelectionSort(int *array,int length)
{
    int min_index = 0;
    int iteration_count  =0;
    for(int i=0;i<length-1;i++)
    {
        min_index = i;
        iteration_count++;
        for(int j=i+1;j<length;j++)
        {
            if(array[j]<array[min_index])
                min_index = j;
        }
        if(min_index != i)
        {
            int temp  = array[min_index];
            array[min_index] = array[i];
            array[i] = temp;
        }
        
    }
    printf("iteration count = %d\n",iteration_count);
}

void InsertionSort(int *array,int length)
{
    int key = 0;
    int iteration_count  =0;
    int j = 0;
    for(int i=1;i<length;i++)
    {
        key = array[i];
        j = i-1;
        while(j>=0 && array[j]>key)
        {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
    printf("iteration count = %d\n",iteration_count);
}
