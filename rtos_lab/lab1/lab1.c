#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "lab1.h"
int main(void)
{
    
    int value_array[ARRAY_LENGTH] = {9,8,2,3,4,5,1,-8,3,8};
    int lengtha = 0,lengthb = 0;
    assert(SmallestElementInArray(value_array,ARRAY_LENGTH) == -8);
    assert(ArrayValueScaler(value_array,ARRAY_LENGTH,SCALE_DATA) == 0);
    assert(StringLength("hello") == 5);
    assert(SearchAorB("",&lengtha,&lengthb) == 0);
    for(int i=0;i<ARRAY_LENGTH;i++)
    {
        printf("%d ",*(value_array+i));
    }
    printf("lena = %d lenb = %d\n",lengtha,lengthb);
    return 0;
}

int SmallestElementInArray(const int *arr_ptr,int length)
{
    int return_value  = -1;
    int smallest_element = 0; 
    if(arr_ptr != NULL)
    {
        return_value = 0;
        smallest_element = *arr_ptr;
        for(int i=0;i<length;i++)
        {
            if(smallest_element > *(arr_ptr+i))
            {
                smallest_element = *(arr_ptr+i);
            }
        }
        return_value = smallest_element;
    }
    return return_value;
}

int ArrayValueScaler(int *arr_ptr,int length,int scale_factor)
{
    int return_value  = -1;
    if(arr_ptr != NULL)
    {
        if(scale_factor != 0)
        {
            for(int i=0;i<length;i++)
            {
                *(arr_ptr + i) = (*(arr_ptr + i))/scale_factor;
                return_value = 0;
            }
        }
    }
    return return_value;
}

int StringLength(const char *str_ptr)
{
    int string_length = 0;
    for(int i =0;i<INT_MAX;i++)
    {
        if(*(str_ptr+i) == '\0')
        {
            break;
        }
        else
            string_length++;
        if(i==INT_MAX)
        {
            string_length = -1;
        }
    }
    return string_length;
}

int SearchAorB(const char *str_ptr,int *lena,int *lenb)
{
    int return_value = -1;
    *lena = 0;
    *lenb = 0;
    if((str_ptr != NULL)&&(lena != NULL)&&(lenb != NULL))
    {
        for(int i =0;i<INT_MAX;i++)
        {
            if(*(str_ptr+i) == '\0')
            {
                return_value = 0;
                break;
            }
           
            if((*(str_ptr+i) == 'A')||(*(str_ptr+i) == 'a'))
            { 
               (*lena)++;

            }
            else if((*(str_ptr+i) == 'B')||(*(str_ptr+i) == 'b'))
            {
                (*lenb)++;
            }
  
        }
    }
    return return_value;
}