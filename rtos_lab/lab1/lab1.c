#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "lab1.h"

int main(void)
{
    
    int value_array[ARRAY_LENGTH] = {9,8,2,3,4,5,1,-8,3,8};
    char str_array[100];
    int lengtha = 0,lengthb = 0;
    int lenalpha = 0,lenws =0;
    assert(SmallestElementInArray(value_array,ARRAY_LENGTH) == -8);
    assert(ArrayValueScaler(value_array,ARRAY_LENGTH,SCALE_DATA) == 0);
    assert(StringLength("hello") == 5);
    assert(SearchAorB("",&lengtha,&lengthb) == 0);
    assert(AlphabetsAndWhitechar(&lenalpha,&lenws) == 0);
    assert(WhiteCharCounter(str_array,100,&lenws) == 0);
    printf("lena = %d lenb = %d\n",lengtha,lengthb);
    printf("lenalpha = %d lenws = %d\n",lenalpha,lenws);
    printf("%s",str_array);
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

int AlphabetsAndWhitechar(int *alpha_len,int *whitespace_len)
{
    int return_value  = -1;
    char c;
    *alpha_len = 0;
    *whitespace_len = 0;
    if((alpha_len != NULL) && (whitespace_len != NULL))
    {
        printf("Enter line of data terminated with \\n \n");
        while((c = getchar())!= '\n')
        {
            if(((c >= 'A')&&(c <= 'Z')) || ((c >= 'a')&&(c <= 'z')))
            {
                return_value = 0;
                (*alpha_len)++;
            }
            else if((c == ' ') || (c == '\t'))
            {
                return_value= 0;
                (*whitespace_len)++;
            }
        }
    }
    return return_value;
}

int WhiteCharCounter(char *str,int maxlimit,int *whitespace_len)
{
    int return_value  = -1;
    int max_len = 0;
    int length_counter = 0;
    int str_length_counter = 0;
    char c;
    *whitespace_len = 0;
    if(whitespace_len != NULL)
    {
        return_value= 0;
        printf("Enter max length\n");
        scanf("%d",&max_len);
        printf("Enter %d characters \n",max_len);
        while((c = getchar())!= EOF)
        {
            if(length_counter < max_len)
            {
                if(str_length_counter >= maxlimit)
                {
                    *(str + str_length_counter) = '\0';
                    
                    break;
                }
                length_counter++;

            }  
            else {
                *(str + str_length_counter) = '\0';
                break;
            }
            if((c == ' ') || (c == '\t')||(c == '\n'))
            {
                (*whitespace_len)++;
            }
            else
            {
                *(str+str_length_counter) = c;
                str_length_counter++;
            }

        }
    }
     return return_value;
}