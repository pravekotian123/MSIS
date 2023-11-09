#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

pthread_t t1,t2,t3,t4,t5;
pthread_mutex_t lock,sem;
int readcount = 0;
void *Reader1(void *data);
void *Reader2(void *data);
void *Reader3(void *data);
void *Writer1(void *str);
void *Writer2(void *str);
int main(void)
{
    if (pthread_mutex_init(&lock, NULL) != 0) { 
    printf("\n mutex init has failed\n"); 
    return 1;
    } 
    if(pthread_mutex_init(&sem,NULL)!= 0)
    {
    printf("\n mutex init has failed\n"); 
    return 1;
    }
    readcount = 0;
    pthread_create(&t1,NULL,Writer1,NULL);
    pthread_create(&t2,NULL,Reader2,NULL);
    pthread_create(&t3,NULL,Writer2,NULL);
    pthread_create(&t4,NULL,Reader1,NULL);
    pthread_create(&t5,NULL,Reader3,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    pthread_join(t5,NULL);
    return 0;
}

void *Reader1(void *data)
{
    pthread_mutex_lock(&lock);
    readcount++;
    printf("rc = %d\n",readcount);
    if(readcount == 1)
    {
        pthread_mutex_lock(&sem);
    }
    pthread_mutex_unlock(&lock);
    printf("rc = %d\n",readcount);
    FILE *r = fopen("sample.txt","r");
    FILE *w = fopen("one.txt","w");
    char ch;
    ch = fgetc(r);
    while(feof(r) != 1)
    {
        fputc(ch,w);
        ch = fgetc(r);
    }
    fclose(r);
    fclose(w);
    pthread_mutex_lock(&lock);
    readcount--;
    if(readcount == 0)
    {
        pthread_mutex_unlock(&sem);
    }
    pthread_mutex_unlock(&lock);
    printf("1 read done \n");
}
void *Reader2(void *data)
{
    pthread_mutex_lock(&lock);
    readcount++;
    printf("rc = %d\n",readcount);
    if(readcount == 1)
    {
        pthread_mutex_lock(&sem);
    }
    printf("rc = %d\n",readcount);
    pthread_mutex_unlock(&lock);
    FILE *r = fopen("sample.txt","r");
    FILE *w = fopen("two.txt","w");
    char ch;
    ch = fgetc(r);
    while(feof(r) != 1)
    {
        fputc(ch,w);
        ch = fgetc(r);
    }
    fclose(r);
    fclose(w);
    pthread_mutex_lock(&lock);
    readcount--;
    if(readcount == 0)
    {
        pthread_mutex_unlock(&sem);
    }
    pthread_mutex_unlock(&lock);
    printf("2 read done \n");
}

void *Reader3(void *data)
{
    pthread_mutex_lock(&lock);
    readcount++;
    printf("rc = %d\n",readcount);
    if(readcount == 1)
    {
        pthread_mutex_lock(&sem);
    }
    printf("rc = %d\n",readcount);
    pthread_mutex_unlock(&lock);
    FILE *r = fopen("sample.txt","r");
    FILE *w = fopen("three.txt","w");
    char ch;
    ch = fgetc(r);
    while(feof(r) != 1)
    {
        fputc(ch,w);
        ch = fgetc(r);
    }
    fclose(r);
    fclose(w);
    pthread_mutex_lock(&lock);
    readcount--;
    if(readcount == 0)
    {
        pthread_mutex_unlock(&sem);
    }
    pthread_mutex_unlock(&lock);
    printf("3 read done \n");
}

void *Writer1(void *str)
{
    pthread_mutex_lock(&sem);
    printf("writing 1\n");
    FILE *f = fopen("sample.txt","a");
    for(int i=0;i<25;i++)
    {
        fputs("Hello World\n",f);
    }
    fclose(f);
    pthread_mutex_unlock(&sem);
}

void *Writer2(void *str)
{
    pthread_mutex_lock(&sem);
    printf("writing 2\n");
    FILE *f = fopen("sample.txt","a");
    for(int i=0;i<10;i++)
    {
        fputs("Hello Everyone\n",f);
    }
    fclose(f);
    pthread_mutex_unlock(&sem);
}