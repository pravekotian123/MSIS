#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

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
    struct Node *head, *tail;
    int count;
};


struct LinkedList * InitializeList();
struct Node * GetNode(int data);
int InsertAtBegining(struct LinkedList * my_list, int data);
int InsertAtEnd(struct LinkedList * my_list, int data);
int InsertAfterData(struct LinkedList * my_list, int data, int element);
int InsertAtPosition(struct LinkedList * my_list, int data, int position);
int DisplayData(struct LinkedList * my_list);

/*
int search_list(List *, int element);
int merge_list(List *, List *);
int split_list(List *, int split_index);

int delete_at_beg(List *);
int delete_at_end(List *);
int delete_element(List *, int element);

List * free_list(List *); // deallocate memory of the list
*/
#endif
