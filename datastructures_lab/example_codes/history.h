#ifndef HISTORY_H_INCLUDED
#define HISTORY_H_INCLUDED

#include <stdio.h>
#include <time.h>

enum OperationType
{
    kInsertData = 1,
    kDeleteData = 2,
    kSearchData = 3
};
struct OperationDetail
{
    enum OperationType type;
    struct tm tm;
};
struct HistNode
{
    struct OperationDetail data;
    struct HistNode *ptr;
};

struct HistorySave
{
    struct HistNode *head, *tail;
    int count;
};

struct HistorySave *InitializeHistorySave();
int AddToHistory(struct HistorySave *my_list, struct OperationDetail data);
struct HistorySave *FreeHistory(struct HistorySave *my_list);
int DisplayHistory(struct HistorySave * my_list);
int DeleteHistory(struct HistorySave * my_list);
#endif