#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    
    int id = 0;
    id = fork();
    if(id > 0)
    {
        wait((int *)NULL);
        printf("I'm parent My 1st call id is %d\n",getpid());
        id = fork();
        if(id > 0)
        {
            wait((int *)NULL);
            printf("I'm parent 2nd call My id is %d\n",getpid());
            id = fork();
            if(id > 0)
            {
                wait((int *)NULL);
                printf("I'm parent 3nd call My id is %d\n",getpid());
            }
            else if(id == 0)
            {
                printf("I'm child c3 My id is %d\n",getpid());
                execl("/bin/pwd","pwd",NULL);
                
            }
        }
        else if(id == 0)
        {
            execl("/bin/ls","ls","-l",NULL);
            printf("I'm child c2 My id is %d\n",getpid());
        }
    }
    else if(id == 0)
    {
        printf("I'm child c1 My id is %d\n",getpid());
        printf("Hello Msis\n");
        execl("/bin/ls","ls",NULL);
    }

    return 0;
}