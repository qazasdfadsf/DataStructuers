#include "init.h"
//循环单链表
typedef struct LNode
{
    ElemType data;
    struct LNode* next;//LinkList L;    ==  LNode* L;
}LNode,*LinkList;
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
#include "init.h"
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DLinklist;
bool InitDLinklist(DLinklist &L)
{//初始化
    L=new DNode;
    if(L==NULL)
    {
        return false;
    }
    L->prior=NULL;
    L->next=NULL;
    return true;
}