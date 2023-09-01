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
        printf("I'm child My id is %d\n",getpid());
        printf("Hello Msis\n");
    }

    return 0;
}