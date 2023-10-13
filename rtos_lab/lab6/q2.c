#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int segment_id;
    char str[10] = {1,2,3,4,5,6,7,8,9,'\0'};
    char temp_str[37];
    char *sm;
    segment_id = shmget(IPC_PRIVATE,37,S_IRUSR|S_IWUSR);
    memcpy(temp_str,str,9);
    memcpy(temp_str+9,"abcdefghijklmnopqrstuvwxyz",27);
    sm = (char *)shmat(segment_id,NULL,0);
    sprintf(sm,"%s",temp_str);
    printf("I'm parent..attached address is %p value is ",sm);
    for(int i=0;i<9;i++)
    {
        printf("%d",*(sm+i));
    }
    printf("%s",sm+9);
    printf("\n");

    int id = fork();
    if(id > 0)
    {
        int status ;
        waitpid(id,&status,0);
        printf("I'm parent..attached address is %p value is ",sm);
        for(int i=0;i<9;i++)
        {
            printf("%d",*(sm+i));
        }
        printf("%s",sm+9);
        printf("\n");
    }
    else if(id == 0)
    {
        char *temp;
        sm = (char *)shmat(segment_id,NULL,0);
        temp = sm;
        while(*temp != '\0')
        {
            if(isalpha(*temp) != 0)
            {
                *temp = (char ) toupper((int )*temp);
            }
            else
            {
                *temp = *temp + 100;
            }
            temp++;
        }
        
        printf("I'm child..attached address is %p value is ",sm);
        for(int i=0;i<9;i++)
        {
            printf("%d",*(sm+i));
        }
        printf("%s",sm+9);
        printf("\n");
    }
    shmdt(sm);
    shmctl(segment_id,IPC_RMID,NULL);
    return 0;
}