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
    char *sm;
    segment_id = shmget(IPC_PRIVATE,52,S_IRUSR|S_IWUSR);
    sm = (char *)shmat(segment_id,NULL,0);
    sprintf(sm, "ABCDEFGHIJKLMANOPQRSTUVWXYZABCDEFGHIJKLMANOPQRSTUVWXYZ");
    printf("I'm parent..attached address is %p value is %s\n",sm,sm);
    int id = fork();
    if(id > 0)
    {
        int status ;
        waitpid(id,&status,0);
        printf("I'm parent..attached address is %p value is %s\n",sm,sm);
    }
    else if(id == 0)
    {
        char *temp;
        sm = (char *)shmat(segment_id,NULL,0);
        temp = sm;
        while(*temp != '\0')
        {
            *temp = (char ) tolower((int )*temp);
            temp++;
        }
        *temp = (char ) tolower((int )*temp++);
        printf("I'm child..attached address is %p value is %s\n",sm,sm);
    }
    shmdt(sm);
    shmctl(segment_id,IPC_RMID,NULL);
    return 0;
}