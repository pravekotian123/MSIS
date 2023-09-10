#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

static int UpdateTailAtCorners(struct LinkedList * my_list);

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
struct Node * GetNode(int data)
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

int InsertAtBegining(struct LinkedList * my_list, int data)
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

int DisplayData(struct LinkedList * my_list)
{
    int return_value  = -1;
    if(my_list != NULL)
    {
        struct Node *temp ;
        int counter = 0;
        for(temp = my_list->head;temp !=NULL;temp = temp->ptr )
        {
            printf("%d ",temp->data);
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

int InsertAtEnd(struct LinkedList * my_list, int data)
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
                my_list->tail->ptr = new_node;
            }
            my_list->count++;
            UpdateTailAtCorners(my_list);
            return_value = 0;
        }
    }
    return return_value;
}

int InsertAfterData(struct LinkedList * my_list, int data, int element)
{
    int return_value  = -1;
    if(my_list != NULL)
    {
        struct Node *temp;
        for(temp = my_list->head;(temp != NULL) && (temp->data != data);temp = temp->ptr );
        
        if(temp != NULL)
        {
           struct Node *new_node = GetNode(element); 
           if(new_node != NULL)
           {
                new_node->ptr = temp->ptr;
                temp->ptr = new_node;
                my_list->count++;
                UpdateTailAtCorners(my_list);
                return_value = 0;
           }
        }
    }
    return return_value;
}

int InsertAtPosition(struct LinkedList * my_list, int data, int position)
{
    int return_value  = -1;
    int position_value = 0;
    if(my_list != NULL)
    {
        if(position == 0)
        {
            return_value = InsertAtBegining(my_list,data);
        }
        else{
            struct Node *temp;
            for(temp = my_list->head;temp != NULL;temp = temp->ptr )
            {
                position_value++;  
                if(position_value == position)
                {
                    break;
                }
               
            }
            if(temp != NULL)
            {
                struct Node *new_node = GetNode(data); 
                if(new_node != NULL)
                {
                    new_node->ptr = temp->ptr;
                    temp->ptr = new_node;
                    my_list->count++;
                    UpdateTailAtCorners(my_list);
                    return_value = 0;
                }
            }
        }
    }
    return return_value;
}


int DeleteAtBegining(struct LinkedList * my_list)
{
    int return_value  = -1;
    if(my_list != NULL)
    {
        
        if(my_list->head != NULL)
        {
            struct Node *temp = my_list->head;
            my_list->head = temp->ptr;
            free(temp);
            my_list->count--;
            UpdateTailAtCorners(my_list);
            return_value = 0;
        }
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

int DeleteData(struct LinkedList * my_list,int data)
{
    int return_value  = -1;
    if((my_list != NULL) && (my_list->head != NULL))
    {
        struct Node *temp = my_list->head;
        if(temp->data == data)
        {
            my_list->head = temp->ptr;
            free(temp);
            return_value = 0;
        }
        else
        {
            while((temp->ptr != NULL) && (temp->ptr->data != data))
            {
                temp = temp->ptr;
            }
            if(temp->ptr != NULL)
            {
                struct Node *backup_node = temp->ptr;
                temp->ptr = temp->ptr->ptr;
                free(backup_node);
                my_list->count--;
                return_value = 0;
            }

        }
        UpdateTailAtCorners(my_list);
        
    }
    return return_value;
}

int SearchElement(struct LinkedList * my_list,int data)
{
    int return_value  = -1;
    int pos_value = 0;
    if((my_list != NULL) && (my_list->head != NULL))
    {
        struct Node *temp = my_list->head;
        while((temp != NULL) && (temp->data != data))
        {
            temp = temp->ptr;
            pos_value++;
        }
        if(temp != NULL)
        {
            return_value = pos_value + 1;
        } 
    }
    return return_value;
}

int MergeList(struct LinkedList * my_list1,struct LinkedList * my_list2)
{
    int return_value  = -1;
    if((my_list1 != NULL) && (my_list2 != NULL))
    {
        struct Node *temp = my_list1->head;
        if(temp == NULL)
        {
            my_list1->head = my_list2->head;
        }
        else{
            while((temp->ptr != NULL))
            {
                temp = temp->ptr;
            }
            temp->ptr = my_list2->head;
        }
        my_list1->tail = my_list2->tail;
        my_list1->count += my_list2->count ;
        return_value = 0;
        /*call free list function*/
    }
    return return_value;
}


struct LinkedList * MergeList(struct LinkedList * my_list1,int split_index)
{
    struct LinkedList *new_list = NULL;
    if((my_list1 != NULL) && (split_index > 0))
    {
        new_list = InitializeList();
        if(new_list == NULL)
        {
            /*not implememnted*/
        
        }
    }
    return new_list;
}
/*


//Lab exercise
int insert_at_pos(List *my_list, int data, int pos);


int search_list(List *my_list, int element)
{
    Node *temp;

    for(temp = my_list->head; temp != NULL; temp = temp->ptr)
        if(temp->data == element) return 1;
    return 0;
}

int delete_at_beg(List *my_list)
{
    Node *temp;
    // check if list is empty, if true return fail
    if(my_list->count == 0) return 0;

    // check if list has one element
    if(my_list->count == 1){
        free(my_list->head);
        my_list->head = NULL;
        my_list->tail = NULL;
    }
    //move the head node
    else
    {
        temp = my_list->head;
        my_list->head = my_list->head->ptr;
        free(temp); //free the previous head
    }

    // decrement the count
    my_list->count--;
    // return succeed
    return DELETED;
}

//Lab Exercise
int delete_at_end(List *my_list)
{
    // check if list empty

    // check if list has one element

    // go to N-1 node

    // free Nth node

    // update tail pointer

    // decrement the counter

}

// Lab Exercise
int delete_element(List *my_list, int element)
{
    // check id list is empty

    // check if the element is at head position

    //check if it is last element

    // search if element exist

    // if not return FAIL

    // if found, free the node

    //decrement count

    //return DELETED
}

List * free_list(List *); // deallocate memory of the list
*/