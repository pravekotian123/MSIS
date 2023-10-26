#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
float FractionalKnapSack(int (*a)[2],int row,int col,int max_weight);
int array[5][2] = 
{
   {25,18},
   {24,15},
   {15,10},
   {6,8},
   {4,5}
};

int main(void)
{
    printf("Max profit = %f \n",FractionalKnapSack(array,5,2,55));
    return 0;
}

float FractionalKnapSack(int (*a)[2],int row,int col,int max_weight)
{
    float max_profit = 0;
    int required_weight = max_weight;
    for(int i=0;i<row;i++)
    {
        for(int j =0;j<row-i-1;j++)
        {
            //printf("%d ",*((int *)(*(a+i))+j));
            float profit_j = (float)(*((int *)(*(a+j))+0)) / (float)(*((int *)(*(a+j))+1));
            float profit_j_next = (float)(*((int *)(*(a+j+1))+0)) / (float)(*((int *)(*(a+j+1))+1));
            if(profit_j < profit_j_next)
            {
                int temp = *((int *)(*(a+j))+0);
                *((int *)(*(a+j))+0) = *((int *)(*(a+j+1))+0);
                *((int *)(*(a+j+1))+0) = temp;
                temp = *((int *)(*(a+j))+1);
                *((int *)(*(a+j))+1) = *((int *)(*(a+j+1))+1);
                *((int *)(*(a+j+1))+1) = temp;
                
            }
        }
    }
    for(int i =0;i<5;i++)
    {
        printf("%d %d ",*((int *)(*(a+i))+0),*((int *)(*(a+i))+1));
        printf("\n");
    }
    for(int i=0;i<row;i++)
    {
        if(required_weight > 0)
        {
           float profit_j = (float)(*((int *)(*(a+i))+0)) / (float)(*((int *)(*(a+i))+1));
           
           if(*((int *)(*(a+i))+1) >= required_weight)
            {
                
                *((int *)(*(a+i))+1) -= required_weight;
                max_profit += profit_j * required_weight;
                printf("profit_per_weight = %f, quantity taken = %d \n",profit_j,required_weight);
                required_weight = 0;
            }
            else
            {
               
                required_weight -= *((int *)(*(a+i))+1);
                max_profit += profit_j * *((int *)(*(a+i))+1);
                printf("profit_per_weight = %f, quantity taken = %d \n",profit_j,*((int *)(*(a+i))+1));
                *((int *)(*(a+i))+1) = 0;
            } 
        }
        else
            break;

    }
    return max_profit;
    
}