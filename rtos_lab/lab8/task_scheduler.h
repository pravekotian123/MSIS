#ifndef TASK_SCHEDULER_INCLUDED
#define TASK_SCHEDULER_INCLUDED

#define MAX_SIZE 5

struct ProcessInfo
{
    int p_id;
    int arrival_time;
    int burst_time;
    int priority;
};
struct ProcessControl
{
    struct ProcessInfo p_info[MAX_SIZE];
    int size;
};

int InsertProcessInfo(struct ProcessControl *pctrl,int arrival_time,int burst_time,int priority);
int InitializeProcessControl(struct ProcessControl *pctrl);
#endif