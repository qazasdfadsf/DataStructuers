#include "init.h"
typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
BSTNode *BST_Search(BSTree T,int key)
{//空间O(1)
    while (T!=NULL&&key!=T->key)
    {
        if(key < T->key)
            T=T->lchild;
        else
            T=T->rchild;
    }
    return T;
}
BSTNode *BSTSearch(BSTree T,int key)
{//空间O(n)
    if(T==NULL)
        return NULL;
    if(key==T->key)
        return T;
    else if(key<T->key)
        return BSTSearch(T->lchild,key);
    else 
        return BSTSearch(T->rchild,key);
}