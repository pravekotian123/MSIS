#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "task_scheduler.h"


int InsertProcessInfo(struct ProcessControl *pctrl,int arrival_time,int burst_time,int priority)
{
    int ret_code = -1;
    if(pctrl != NULL)
    {
        if(pctrl->size < MAX_SIZE)
        {
            (pctrl->p_info[pctrl->size]).p_id = pctrl->size;
            pctrl->p_info[pctrl->size].arrival_time = arrival_time;
            pctrl->p_info[pctrl->size].burst_time = burst_time;
            pctrl->p_info[pctrl->size].priority = priority;
            pctrl->size++;
            ret_code = 0;
        }
    }
    return ret_code;
}

int InitializeProcessControl(struct ProcessControl *pctrl)
{
    if(pctrl != NULL)
    {
        pctrl->size = 0;
    }
}