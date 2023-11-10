#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE (5U)
int array[BUFFER_SIZE] = {1,2,3,4,5};
int buf_index = 0;
pthread_t t1,t2;
sem_t full,empty;
pthread_mutex_t lock;
void *Producer(void *ptr);
void *Consumer(void *ptr);
int main(void)
{
    if(pthread_mutex_init(&lock,NULL) != 0)
    {
        printf("mutex init failed \n");
        return 1;
    }
    if(sem_init(&full,0,0) != 0)
    {
        printf("sem init failed \n");
        return 1;
    }
    if(sem_init(&empty,0,0) != 0)
    {
        printf("sem init failed \n");
        return 1;
    }
    pthread_create(&t1,NULL,Producer,NULL);
    pthread_create(&t2,NULL,Consumer,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}

void *Producer(void *ptr)
{
    sem_wait(&empty);
    printf("hi\n");
    pthread_mutex_lock(&lock);
    array[buf_index] = *(int *)ptr;
    if(buf_index < (BUFFER_SIZE - 1))
    {
        buf_index++;
    }
    else
    buf_index = 0;
    pthread_mutex_unlock(&lock);
    sem_post(&full);
}

void *Consumer(void *ptr)
{
    sem_wait(&full);
     printf("hello\n");
    pthread_mutex_lock(&lock);
    if(buf_index > 0)
    {
        buf_index--;
    }
    pthread_mutex_unlock(&lock);
    sem_post(&empty);
}