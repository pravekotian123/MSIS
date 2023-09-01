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
        printf("I'm parent My id is %d\n",getpid());
    }
    else if(id == 0)
    {
        printf("I'm child's 1st call. My id is %d\n",getpid());
        id = fork();
        if(id > 0)
        {
            wait((int *)NULL);
            id = fork();
            if(id == 0)
            {
                printf("I'm 1st child's 1st child. My id is %d\n",getpid());
                execl("/bin/mv","mv","output","output.exe",NULL);
            }
            else if(id > 0)
            {
                wait((int *)NULL);
                printf("I'm child's 2nd call. My id is %d\n",getpid());
                execl("./output.exe","output.exe",NULL);
            }

            
        }
        else if(id == 0)
        {
            id = fork();
            if(id == 0)
            {
                execl("/bin/gcc","gcc","-o","output","display_100_odd.c",NULL);
            }
        }
        
    }

    return 0;
}