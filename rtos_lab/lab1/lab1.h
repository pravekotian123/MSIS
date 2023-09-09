#ifndef LAB1_HEADER
#define LAB1_HEADER

#include <stdint.h>

#define ARRAY_LENGTH (10U)
#define SCALE_DATA (-2U)
int SmallestElementInArray(const int *arr_ptr,int length);
int ArrayValueScaler(int *arr_ptr,int length,int scale_factor);
int StringLength(const char *str_ptr);
int SearchAorB(const char *str,int *lena,int *lenb);
#endif