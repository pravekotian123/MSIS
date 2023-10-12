#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
void* f1(void *ptr);
void* f2(void *ptr);

#define ROW_MAX (3U)
#define COLUMN_MAX (4U)

struct Array2D 
{
    int arr[ROW_MAX][COLUMN_MAX];
    int target_col;
    int target_row;
};
pthread_t t1,t2,t3;

int main()
{
    void *status;
    int total_sum = 0;
    struct Array2D array_2d = 
    {
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9,10,11,12}
        },
        0,
        0
    };
    pthread_attr_t a1;
    pthread_attr_init(&a1);
   
    for(int i =0;i < COLUMN_MAX; i++)
    {
        array_2d.target_col = i;
        pthread_create(&t1,&a1,f1,&array_2d);
        pthread_join(t1,&status);
        total_sum +=  *((int *)status);
        printf("Column no : %d. Sum is %d\n",i,*((int *)status));
    }
    printf("Total sum of all column is %d\n",total_sum);
    printf("\n");
    total_sum = 0;

    for(int i =0;i < ROW_MAX; i++)
    {
        array_2d.target_row = i;
        pthread_create(&t1,&a1,f2,&array_2d);
        pthread_join(t1,&status);
        total_sum +=  *((int *)status);
        printf("Row no : %d, Sum is %d\n",i,*((int *)status));
    }
    printf("Total sum of all row is %d\n",total_sum);
    printf("\n");
    write(1,"hey\n",strlen("hey\n"));
    total_sum = 0;

    return 0;
}

void* f1(void *ptr)
{
    int *info_ptr = (int *)&(((struct Array2D *)ptr)->arr[0][0]);
    int *col_sum = (int *)malloc(sizeof(int));
    if(col_sum != NULL)
    {
        for(int i = 0;i < ROW_MAX;i++)
        {
            for(int j=0;j< COLUMN_MAX;j++)
            {
                if(j == ((struct Array2D *)ptr)->target_col)
                {
                    *col_sum += *((info_ptr + COLUMN_MAX*i) + j);
                }
            }
        }
    }

   // pthread_exit(NULL);
    return (void *)col_sum;
}

void* f2(void *ptr)
{
    int *info_ptr = (int *)&(((struct Array2D *)ptr)->arr[0][0]);
    int *row_sum = (int *)malloc(sizeof(int));
    if(row_sum != NULL)
    {
        for(int i = 0;i < ROW_MAX;i++)
        {
            for(int j=0;j< COLUMN_MAX;j++)
            {
                if(i == ((struct Array2D *)ptr)->target_row)
                {
                    *row_sum += *((info_ptr + COLUMN_MAX*i) + j);
                }
            }
        }
    }

   // pthread_exit(NULL);
    return (void *)row_sum;
}

