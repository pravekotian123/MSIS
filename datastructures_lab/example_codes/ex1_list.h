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
struct Node * GetNode(struct Student data);
int InsertAtBegining(struct LinkedList * my_list, struct Student data);
int InsertAtEnd(struct LinkedList * my_list, struct Student data);
int InsertAfterData(struct LinkedList * my_list, int data, struct Student element);
int InsertAtPosition(struct LinkedList * my_list, int data, struct Student position);
int DeleteAtBegining(struct LinkedList * my_list);
int DeleteAtEnd(struct LinkedList * my_list);
int DisplayData(struct LinkedList * my_list);
int DeleteData(struct LinkedList * my_list,struct Student data);
int SearchElement(struct LinkedList * my_list,struct Student data);
int MergeList(struct LinkedList * my_list1,struct LinkedList * my_list2);
#endif