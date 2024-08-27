#include "init.h"
typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
BSTNode *BST_Search(BSTree T,int key)
{
    while (T!=NULL&&key!=T->key)
    {
        if(key < T->key)
            T=T->lchild;
        else
            T=T->rchild;
    }
    return T;
}