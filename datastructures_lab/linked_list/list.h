#ifndef LIST_HEADER_INCLUDED
#define LIST_HEADER_INCLUDED


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