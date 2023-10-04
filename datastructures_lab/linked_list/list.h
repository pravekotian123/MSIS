#ifndef LIST_HEADER
#define LIST_HEADER

#define FAILED 0
#define INSERT_SUCCESS 1
#define DELETED 1

struct Node
{
    int data;
    struct Node *ptr;
};

struct LinkedList
{
    struct Node *head;
};


struct LinkedList * InitializeList();
struct Node * GetNode(int data);
int InsertAtBegining(struct LinkedList * my_list, int data);
int InsertAtEnd(struct LinkedList * my_list, int data);
int InsertAfterData(struct LinkedList * my_list, int data, int element);
int InsertAtPosition(struct LinkedList * my_list, int data, int position);
int DeleteAtBegining(struct LinkedList * my_list);
int DeleteAtEnd(struct LinkedList * my_list);
int DisplayData(struct LinkedList * my_list);
int DeleteData(struct LinkedList * my_list,int data);
int SearchElement(struct LinkedList * my_list,int data);
int MergeList(struct LinkedList * my_list1,struct LinkedList * my_list2);
/*
int split_list(List *, int split_index);


List * free_list(List *); // deallocate memory of the list
*/
#endif