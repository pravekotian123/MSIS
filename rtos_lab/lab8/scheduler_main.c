#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include "task_scheduler.h"
int main(void)
{
    struct ProcessControl p_control;
    InitializeProcessControl(&p_control);
    assert(InsertProcessInfo(&p_control,0,1,0) == 0);
    return 0;
}