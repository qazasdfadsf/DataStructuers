#include "init.h"
typedef struct LNode
{
    ElemType data;
    struct LNode* next;//LinkList L;    ==  LNode* L;
}LNode,*LinkList;
bool InitList(LinkList &L)
{//初始化
    /*不带头的单链表
    return (L=NULL);
    */
    //带头的单链表
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
{//单链表判空
    /*不带头结点
    if (L==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    */
    //带头结点
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