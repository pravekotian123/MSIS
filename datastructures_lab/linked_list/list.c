#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

static struct Node * GetNode(void *data_ptr,int size);

struct List *InitializeList()
{
    struct List *list;
    list = (struct List *)malloc(sizeof(struct List));
    if(list != NULL)
    {
        list->head = NULL;
    }
    return list;
}

static struct Node * GetNode(void *data_ptr,int size) {
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    if(new_node != NULL) {
        new_node->data = malloc(size);
        if(new_node->data != NULL) {
            memcpy(new_node->data,data_ptr,size);
            new_node->ptr = NULL;
        }
        else {
            free(new_node);
            new_node = NULL;
        }
    }
    return new_node;
}

int InsertAtBegining(struct List *list,void *data_ptr,int size)
{
    int return_value  = -1;
    if(list != NULL) {
        struct Node *new_node = GetNode(data_ptr,size); 
        if(new_node != NULL) {
            if(list->head == NULL) {
                list->head = new_node;
            }
            else {
                new_node->ptr = list->head;
                list->head = new_node;
            }
            return_value = 0;
        }
    }
    return return_value;
}


int InsertAtEnd(struct List *list,void *data_ptr,int size) {
    int return_value  = -1;
    if(list != NULL) {
        struct Node *new_node = GetNode(data_ptr,size); 
        if(new_node != NULL) {
            if(list->head == NULL) {
                list->head = new_node;
            }
            else {
                struct Node *temp = list->head;
                while(temp->ptr != NULL) {
                    temp = temp->ptr;
                }
                temp->ptr = new_node;
            }
            return_value = 0;
        }
    }
    return return_value;
}


int InsertAtPosition(struct List *list, void *data_ptr, int size, int position) {
    int return_value  = -1;
    int position_value = 0;
    if(list != NULL) {
        if(position == 0) {
            return_value = InsertAtBegining(list,data_ptr,size);
        }
        else {
            struct Node *temp = list->head;
            while(temp != NULL) {
                  if(++position_value < position) {
                    temp = temp->ptr;
                }
                else {
                    break;
                }
            }
            if(temp != NULL) {
                struct Node *new_node = GetNode(data_ptr,size); 
                if(new_node != NULL) {
                    new_node->ptr = temp->ptr;
                    temp->ptr = new_node;
                    return_value = 0;
                }
            }
        }
    }
    return return_value;
}


int DeleteAtBegining(struct List *list) {
    int return_value  = -1;
    if(list != NULL) {
        if(list->head != NULL) {
            struct Node *temp = list->head;
            list->head = temp->ptr;
            free(temp);
            return_value = 0;
        }
    }
    return return_value;
}

int DeleteAtEnd(struct List *list) {
    int return_value  = -1;
    if((list != NULL)  && (list->head != NULL)) {
        struct Node *temp = list->head;
        if(temp->ptr == NULL) {
            free(temp);
            list->head = NULL;
            
        }
        else {
            while(temp->ptr->ptr != NULL)
            {   
                temp = temp->ptr;
            }
            free(temp->ptr);
            temp->ptr = NULL;
        }
        return_value = 0;
    }
    return return_value;
}


void *FetchDataByPosition(struct List *list,int position) {
    int current_position = 0;
    void *return_ptr = NULL;
    if(list != NULL) {
        struct Node *temp = list->head;
        while(current_position < position) {
            if(temp != NULL) {
                temp = temp->ptr;
            }
            else {
                break;
            }
            current_position++;
        }
        if(temp != NULL) {
           return_ptr = temp->data;
        }

    }
    return return_ptr;
}