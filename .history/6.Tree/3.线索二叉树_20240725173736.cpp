#include "init.h"
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;
ThreadNode *pre=NULL;//指向当前访问节点的前驱
void visit(ThreadNode *q)
{//线索化
    if (q->lchild==NULL)
    {
        q->lchild=pre;
        q->ltag=1;
    }
    if (pre!=NULL&&pre->rchild==NULL)
    {
        pre->rchild=q;
        pre->rtag=1;
    }
    pre=q;
}
void InThread(ThreadTree T)
{//中序遍历二叉树，一边遍历一边线索化
    if (T!=NULL)
    {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

void InThread(ThreadTree p,ThreadTree &pre)
{//线索化
    if (p!=NULL)
    {
        InThread(p->lchild,pre);
        if (p->lchild==NULL)
        {
            p->lchild=pre;
            p->ltag=1;
        }
        if (pre!=NULL&&pre->rchild==NULL)
        {
            pre->lchild=p;
            pre->rtag=1;
        }
        pre=p;
        InThread(p->rchild,pre);
    }
}
void CreateInThread(ThreadTree T)
{//中序线索化
    ThreadTree pre=NULL;
    if (T!=NULL)
    {
        InThread(T,pre);
        pre->rchild=NULL;
        pre->rtag=1;
    }
}


void PreThread(ThreadTree T)
{//先序线索化
    if(T!=NULL){
        visit(T);
        if(T->ltag==0)
            PreThread(T->lchild);
        PreThread(T->rchild);
    }
}
void PostThread(ThreadTree T)
{//后序线索化
   if (T!=NULL)
    {
        if(T->ltag==0)
            PostThread(T->lchild);
        PostThread(T->rchild);
        visit(T);
    }
}
//===========================中序后继
ThreadNode *Firstnode(ThreadNode *p){
    while (p->ltag==0)
    {
        p=p->lchild;
    }
    return p;
}
ThreadNode *Nextnode(ThreadNode *p){
    if (p->rtag==0)
    {
        return Firstnode(p->rchild);
    }
    else
    {
        return p->rchild;
    }
}
//============================先序前驱
ThreadNode *Lastnode(ThreadNode *p){
    while (p->ltag==0)
    {
        p=p->lchild;
    }
    return p;
}
ThreadNode *Prenode(ThreadNode *p){
    if (p->rtag==0)
    {
        return Firstnode(p->rchild);
    }
    else
    {
        return p->rchild;
    }
}
void RevInorder(ThreadNode *T){
    for (ThreadNode *p  = Lastnode(T);p!=NULL ;p=Prenode(p))
    {
        visit(p);
    }
    
}