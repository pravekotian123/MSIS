#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../trees/btree_linked_list/btree.h"

int main(void)
{
    struct Btree *btree = CreateUserEnteredTree();
    PrintIntegerTree(btree);
    printf("hello world\n");
    return 0;
}