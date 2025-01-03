#include "init.h"
//循环单链表
typedef struct LNode
{
    ElemType data;
    struct LNode* next;//LinkList L;    ==  LNode* L;
}LNode,*LinkList;//Circular Linked List
bool InitList(LinkList &L)
{//初始化
    L=new LNode;//创建头节点
    //L=(LNode*)malloc(sizeof(LNode));
    if(L==NULL)
    {//内存不足，分配失败
        return false;
    }
    L->next=L;
    return true;
}
bool Empty(LinkList L)
{//循环单链表判空
    if(L->next==L)
        return true;
    else
        return false;
}
bool isTail(LinkList L,LNode *p)
{
    if (p->next==L) 
        return true;
    else
        return false;
}

//循环双链表
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DLinkList;
bool InitDLinkList(DLinkList &L)
{//初始化
    L=new DNode;
    if(L==NULL)
    {
        return false;
    }
    L->prior=L;
    L->next=L;
    return true;
}
bool Empty(DLinkList L)
{
    if(L->next==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isTail(DLinkList L,DNode *p)
{
    if (p->next==L) 
        return true;
    else
        return false;
}
//与双链表不同
bool InsertNextDNode(DNode *p,DNode *s)
{//后插操作 
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;
    return true;
}
//与双链表不同
bool DeleteNextDNode(DNode *p)
{//删除p的后继节点
    DNode *q=p->next;
    p->next=q->next;
    q->next->prior=p;
    delete q;
    return true;
}