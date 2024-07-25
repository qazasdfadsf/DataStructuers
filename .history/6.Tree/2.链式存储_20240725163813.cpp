#include "init.h"
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
    // struct BiTNode *parent;视情况而定
}BiTNode,*BiTree;
void visit(BiTree T)
{//访问子树
    printf("%d",T->data);
}
void PreOrder(BiTree T)
{//先序遍历
    if (T!=NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void InOrder(BiTree T)
{//中序遍历
    if (T!=NULL)
    {
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}
void PostOrder(BiTree T)
{//后序遍历
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
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while (!isEmpty(Q))
    {
        DeQueue(Q,p);
        visit(p);
        if(p->lchild!=NULL){
            EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL){
            EnQueue(Q,p->rchild);
        }
    }
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
