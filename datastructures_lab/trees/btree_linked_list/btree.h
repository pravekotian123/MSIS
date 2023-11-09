#ifndef BTREE_H_
#define BTREE_H_

struct Btree{
    struct Btree *lchild,*rchild;
    void *data;
};

struct Btree *CreateUserEnteredTree(void);
void PrintIntegerTree(struct Btree *btree);
#endif