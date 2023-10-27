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
pthread_mutex_t lock; 
int main()
{
    pthread_attr_t a1;
    pthread_attr_init(&a1);
    if (pthread_mutex_init(&lock, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    } 
    pthread_create(&t1,&a1,f1,NULL);
    pthread_create(&t2,&a1,f2,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
  
    return 0;
}
void* f1(void *ptr)
{
    pthread_mutex_lock(&lock); 
    FILE *basefile = fopen("test.txt","r");/*null check*/
    FILE *targetfile = fopen("sample2.txt","w");/*null check*/
    char ch = fgetc(basefile);
    while(feof(basefile) != 1)
    {
        fputc(ch,targetfile);
        ch = fgetc(basefile);
    }
    fclose(basefile);
    fclose(targetfile);
    pthread_mutex_unlock(&lock); 
    return NULL;
}

void* f2(void *ptr)
{
    char ch;
    pthread_mutex_lock(&lock); 
    printf("Enter message ended with new line\n");
    FILE *targetfile = fopen("sample2.txt","a");/*null check*/
    scanf("%c",&ch);
    while(ch != '\n')
    {
        fputc(ch,targetfile);
        scanf("%c",&ch);
    }
    fclose(targetfile);
    pthread_mutex_unlock(&lock); 
    return NULL;
}
