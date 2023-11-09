#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "btree.h"
int arr[11] = {1,2,3,4,5,6,7,0,0,0,0};
int arr_index = 0;
struct Btree *CreateUserEnteredTree(void){
    struct Btree *root = NULL;
    int data = -1;
    printf("Enter data \n");
    scanf("%d",&data);
    while(data != -1)
    {
        root = (struct Btree *)malloc(sizeof(struct Btree));
        if(root !=  NULL)
        {
            root->data = (int *)malloc(sizeof(int));
            *(int *)root->data = data;
            printf("For left child of %d\n",*(int *)root->data);
            root->lchild = CreateUserEnteredTree();
            printf("For right child of %d\n",*(int *)root->data);
            root->rchild = CreateUserEnteredTree();
            break;
        }
    }
    return root;
}

void PrintIntegerTree(struct Btree *btree)
{
    if(btree != NULL)
    {
        PrintIntegerTree(btree->lchild);
        printf("%d|--",*(int *)btree->data);
        PrintIntegerTree(btree->rchild); 
        printf("  ");
    }
    else
        printf("\n");
}