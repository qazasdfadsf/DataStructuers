#include "init.h"
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void visit(BiTree T){
    printf("%d",T->data);
}
void PreOrder(BiTree T){
    if (T!=NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void InOrder(BiTree T){
    if (T!=NULL)
    {
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}
void PostOrder(BiTree T){
    if (T!=NULL)
    {
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        visit(T);
    }
}
int treeDepth(BiTree T){
    if (T==NULL)
    {
        return 0;
    }
    else
    {
        int l=treeDepth(T->lchild);
        int r=treeDepth(T->rchild);
        return l>r?l+1:r+1;
    }
}
void LevelOrder(BiTree T){
    // LinkQueue Q;
}
int main()
{
    BiTree root=NULL;
    root=new BiTNode;
    root->data={1};//root->data.value=1;
    root->lchild=NULL;
    root->rchild=NULL;
    return 0;
}
