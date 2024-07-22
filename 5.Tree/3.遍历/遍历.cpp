#include<iostream>
#include "Queue.h"
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct LinkNode{
    BiTNode *data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode*front,*rear;
}LinkQueue;
void visit(BiTree T){
    printf("%c",T->data);
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