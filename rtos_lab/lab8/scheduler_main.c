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
#include <assert.h>
#include "../../datastructures_lab/linked_list/list.h"
#include "task_scheduler.h"
int main(void)
{
    struct ProcessControl p_control;
    struct List *fcfs_list = NULL;
    assert(InitializeProcessControl(&p_control) == 0);
    assert(InsertProcessInfo(&p_control,0,1,0) == 0);
    fcfs_list = InitializeList();
    assert(fcfs_list != NULL);
    INSERT_AT_BEGINING(fcfs_list,&(p_control.p_info[0].p_id));
    return 0;
}