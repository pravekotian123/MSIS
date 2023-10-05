#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
void* f1(void *ptr);
void* f2(void *ptr);

struct ArrayInfo
{
    int a[10];
    int length;
};
pthread_t t1,t2,t3;
int main()
{
    struct ArrayInfo a_info1 = 
    {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        10
    };
    pthread_attr_t a1;
    pthread_attr_init(&a1);
    
    pthread_create(&t1,&a1,f1,&a_info1);
    pthread_create(&t2,&a1,f2,&a_info1);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
  
    return 0;
}
void* f1(void *ptr)
{
    struct ArrayInfo *info_ptr = (struct ArrayInfo *)ptr;
    for(int i = 0;i < (info_ptr->length);i++)
    {
        printf("%d ",info_ptr->a[i]);
    }
    printf("\n");
    pthread_exit(NULL);
    return NULL;
}

void* f2(void *ptr)
{
    struct ArrayInfo *info_ptr = (struct ArrayInfo *)ptr;
    for(int i = 0;i < (info_ptr->length);i++)
    {
        if((info_ptr->a[i] & 0x01) == 0x01)
        {
             printf("%d ",info_ptr->a[i]);
        }
       
    }
    printf("\n");
    pthread_exit(NULL);
    return NULL;
}
