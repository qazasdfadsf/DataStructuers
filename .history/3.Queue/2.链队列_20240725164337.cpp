#include "init.h"
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode * next;
}LinkNode;
typedef struct 
{
    LinkNode *front,*rear;
}LinkQueue;
void InitQueue(LinkQueue &Q)
{
    //带头结点
    Q.front = Q.rear = new LinkNode;
    Q.front->next=NULL;
    /*不带头结点
    Q.front=NULL;
    Q.rear=NULL;
    */
}
bool isEmpty(LinkQueue &Q)
{
    //带头结点
    if (Q.front==Q.rear)
        return true;
    else
        return false;
    /*不带头结点
    if(Q.front==NULL)
        return true;
    else
        return false;
    */
}
void EnQueue(LinkQueue &Q,ElemType &x)
{//入队
    LinkNode *s=new LinkNode;
    s->data=x;
    s->next=NULL;
    //带头结点
    Q.rear->next=s;
    Q.rear=s;
    /*不带头结点
    if (Q.front==NULL)
    {
        Q.front=s;
        Q.rear=s;
    }
    else
    {
        Q.rear->next=s;
        Q.rear=s;
    }
    */
}
bool DeQueue(LinkQueue &Q,ElemType &x)
{//出队
    //带头结点
    if(Q.front==Q.rear)
    {
        return false;
    }
    LinkNode* p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
    {
        Q.rear=Q.front;
    }
    delete p;
    return true;
}