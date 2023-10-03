#include <stdlib.h>
#include <stdio.h>

#include "history.h"

static struct HistNode  * GetNode(struct OperationDetail data);

struct HistorySave *InitializeHistorySave()
{
    struct HistorySave *my_list;
    my_list = (struct HistorySave *)malloc(sizeof(struct HistorySave));
    if(my_list != NULL)
    {
        my_list->head = NULL;
        my_list->count = 0;
    }
    return my_list;
}

static struct HistNode  * GetNode(struct OperationDetail data)
{
    struct HistNode  * new_node;
    new_node = (struct HistNode *)malloc(sizeof(struct HistNode ));
    if(new_node != NULL)
    {
        new_node->data = data;
        new_node->ptr = NULL;
    }
    return new_node;
}

int AddToHistory(struct HistorySave *my_list, struct OperationDetail data)
{
    int return_value  = -1;
    if(my_list != NULL)
    {
        struct HistNode *new_node = GetNode(data); 
        if(new_node != NULL)
        {
            if((my_list->head == NULL))
            {
                my_list->head = new_node;
            }
            else{
                new_node->ptr = my_list->head;
                my_list->head = new_node;
            }
            my_list->count++;
            return_value = 0;
        }
    }
    return return_value;
}

int DisplayHistory(struct HistorySave *my_list)
{
    int return_value  = -1;
    if(my_list != NULL)
    {
        struct HistNode *temp ;
        int counter = 0;
        for(temp = my_list->head;temp !=NULL;temp = temp->ptr )
        {
            char *op_type = NULL;
            if(kInsertData == temp->data.type)
            {
                op_type = "InsertData";
            }
            else if(kDeleteData == temp->data.type){
                op_type = "DeleteData";
            }
            else if(kSearchData == temp->data.type){
                op_type = "SearchData";
            }
            printf("Operation type = %s, date = %d-%d-%d, time = %d:%d\n",op_type,temp->data.tm.tm_mday,temp->data.tm.tm_mon + 1,temp->data.tm.tm_year + 1900,temp->data.tm.tm_hour, temp->data.tm.tm_min);
            if(++counter == my_list->count)
            {
                return_value = -1;
                break;
            }
            else
            {
                return_value = 0;
            }
            
        }
        printf("\n");
    }
    return return_value;
}