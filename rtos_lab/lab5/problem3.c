#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int id = 0;
    id =fork();
    if(id < 0)
    {
        printf("child creation failed \n");
        exit(-1);
    }
    else if(id == 0)
    {
        sleep(8);
        printf("I'm child my id is  =%d \n",getpid());
        printf("My parent's id is  =%d \n",getppid());
    }
    else if(id >0 )
    {
        printf("I'm parent my id is  =%d \n",getpid());
        wait((int *)NULL);
         printf("I'm parent i got control again\n");
    }
    return 0;
}