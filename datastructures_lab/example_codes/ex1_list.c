#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ex1_list.h"

static int UpdateTailAtCorners(struct LinkedList * my_list);
static struct Node * GetNode(struct Student data);;

struct LinkedList * InitializeList()
{
    struct LinkedList *my_list;
    my_list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    if(my_list != NULL)
    {
        my_list->head = my_list->tail = NULL;
        my_list->count = 0;
    }
    return my_list;
}

/*can be static*/
static struct Node * GetNode(struct Student  data)
{
    struct Node * new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    if(new_node != NULL)
    {
        new_node->data = data;
        new_node->ptr = NULL;
    }
    return new_node;
}

int InsertAtBegining(struct LinkedList * my_list,  struct Student data)
{
    int return_value  = -1;
    if(my_list != NULL)
    {
        struct Node *new_node = GetNode(data); 
        if(new_node != NULL)
        {
            if((my_list->head == NULL)||(my_list->tail == NULL))
            {
                my_list->head = new_node;
            }
            else{
                new_node->ptr = my_list->head;
                my_list->head = new_node;
            }
            my_list->count++;
            UpdateTailAtCorners(my_list);
            return_value = 0;
        }
    }
    return return_value;
}

static int UpdateTailAtCorners(struct LinkedList * my_list)
{
    int return_value  = -1;
    if(my_list != NULL)
    {
        if((my_list->count  == 0) || (my_list->count  == 1))
        {
            my_list->tail = my_list->head;
        }
        return_value = 0;
    }
    return return_value;
}

int DeleteAtEnd(struct LinkedList * my_list)
{
    int return_value  = -1;
    if((my_list != NULL) && (my_list->head != NULL))
    {
        struct Node *temp = my_list->head;
        if(temp->ptr == NULL)
        {
            free(temp);
            my_list->head = NULL;
            
        }
        else{
            while(temp->ptr->ptr != NULL)
            {   
                temp = temp->ptr;
            }
            free(temp->ptr);
            temp->ptr = NULL;
            my_list->tail = temp;
        }
         my_list->count--;
        UpdateTailAtCorners(my_list);
        return_value = 0;
    }
    return return_value;
}

int DisplayData(struct LinkedList * my_list)
{
    int return_value  = -1;
    if(my_list != NULL)
    {
        struct Node *temp ;
        int counter = 0;
        for(temp = my_list->head;temp !=NULL;temp = temp->ptr )
        {
            printf("Name = %s, %d = class \n",temp->data.name,temp->data.stu_class);
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

int SearchElementByName(struct LinkedList * my_list,char *name)
{
    int return_value = -1;
    if(my_list != NULL)
    {
        struct Node *temp ;
        for(temp = my_list->head;temp !=NULL;temp = temp->ptr )
        {
            if(strcmp(temp->data.name,name) == 0)
            {
                return_value = 0;
                break;
            }
            
        }
    }
    return return_value;
}

struct LinkedList *FreeList(struct LinkedList * my_list)
{
    if(my_list != NULL)
    {
        while(DeleteAtEnd(my_list) != -1);
        free(my_list);
    }
    return NULL;
}