#include <stdio.h>
#include "sort.h"



int main(void)
{
    int a[7] = {4,9,8,7,6,5,10};
   // 
    for(int i = 0;i<7;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    qsort(a,0,6);
    for(int i = 0;i<7;i++)
    {
        printf("%d ",a[i]);
    }

}

void qsort(int *a,int start, int end)
{
    printf("start= %d, end =%d \n",start,end);
    
    int l =start,r =end;
    if(l>=r){
        return;
    }
    int pivot = a[l+(r-l)/2];
    while(l<=r)
    {
        
        while(a[l]<pivot)
        {
            l++; 
        }
        while(a[r]>pivot)
        {
            r--;
        }
        if(l<=r)
        {
            int temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            l++;
            r--;
        }
    }
        
    qsort(a,start,l-1 );
    qsort(a,l+1,end);
      
    
}