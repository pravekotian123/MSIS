
struct Node{
    int data;
    struct Node *link;
};
struct List{
    struct Node *head;
};
struct Node *GetNode(int data);
int InsertAtBegining(struct List *list,int data);
void PrintList(struct List *list);