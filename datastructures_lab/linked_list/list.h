#ifndef LIST_HEADER_INCLUDED
#define LIST_HEADER_INCLUDED

#define INSERT_AT_BEGINING(my_list,data_ptr) (InsertAtBegining(my_list,data_ptr,sizeof(typeof(*data_ptr))))
#define INSERT_AT_POSITION(my_list,data_ptr,position) (InsertAtPosition(my_list,data_ptr,sizeof(typeof(*data_ptr)),position))
#define INSERT_AT_END(my_list,data_ptr) (InsertAtEnd(my_list,data_ptr,sizeof(typeof(*data_ptr))))
#define DELETE_AT_END(my_list) (DeleteAtEnd(my_list))
#define DELETE_AT_BEGINING(my_list) (DeleteAtBegining(my_list))

struct Node
{
    void *data;
    struct Node *ptr;
};

struct List
{
    struct Node *head;
};


struct List * InitializeList();
int InsertAtBegining(struct List * my_list,void *data_ptr,int size);
int InsertAtPosition(struct List *list, void *data_ptr, int size, int position);
int InsertAtEnd(struct List *list,void *data_ptr,int size);
int DeleteAtEnd(struct List *list);
int DeleteAtBegining(struct List *list);
void *FetchDataByPosition(struct List *list,int position);
#endif