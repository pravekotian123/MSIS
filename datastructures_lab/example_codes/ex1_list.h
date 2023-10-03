#ifndef EX1_HEADER
#define EX1_HEADER



#define FAILED (0U)
#define INSERT_SUCCESS (1U)
#define DELETED (1U)



struct Student
{
    char name[20];
    int stu_class;
};

struct Node
{
    struct Student data;
    struct Node *ptr;
};

struct LinkedList
{
    struct Node *head, *tail;
    int count;
};


struct LinkedList * InitializeList();

int InsertAtBegining(struct LinkedList * my_list, struct Student data);
int DeleteAtEnd(struct LinkedList * my_list);
int SearchElementByName(struct LinkedList * my_list,char *name);
struct LinkedList *FreeList(struct LinkedList * my_list);
#endif