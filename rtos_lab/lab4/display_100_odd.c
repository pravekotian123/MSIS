#include <stdint.h>
#include <stdio.h>
int main(void)
{
    for(int i=0;i<200;i++)
    {
        if(i%2 == 0)
        {
            printf("%d ",i+1);
        }
         
    }
    printf("\n");
    return 0;
}