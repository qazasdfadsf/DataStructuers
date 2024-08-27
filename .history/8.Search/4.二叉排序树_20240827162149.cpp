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
int BST_Insert(BSTree &T,int k)
{//
    if (T==NULL)
    {
        T=new BSTNode;
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }
    else if(k==T->key)
        return 0;
    else if(k<T->key)
        return BST_Insert(T->lchild,k);
    else
        return BST_Insert(T->rchild,k);
}
//非递归Insert


void Creat_BST(BSTree &T,int str[],int n)
{
    T=NULL;
    int i=0;
    while (i<n)
    {
        BST_Insert(T,str[i]);
        i++;
    }
    
}