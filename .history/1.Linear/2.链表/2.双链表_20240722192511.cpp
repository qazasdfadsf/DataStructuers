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
bool Empty(DLinklist L)
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
bool InsertNextDNode(DNode *p,DNode *s)
{//后插操作
    if(p==NULL||s==NULL)
    {
        return false;
    }
    s->next=p->next;
    if(p->next!=NULL)
    {
        p->next->prior=s;
    }
    s->prior=p;
    p->next=s;
    return true;
}
bool DeleteNextDNode(DNode *p)
{//删除p的后继节点
    if(p==NULL)
    {
        return false;
    }
    DNode *q=p->next;
    if(q==NULL)
    {
        return false;
    }
    p->next=q->next;
    if(q->next!=NULL)
    {
        q->next->prior=p;
    }
    delete q;
    return true;
}
void DestoryList(DLinklist &L)
{
    while(L->next!=NULL){
        DeleteNextDNode(L);
    }
    delete L;
    L=NULL;
}
int main(){
    DLinklist L;
    InitDLinklist(L);
    return 0;
}
/*

*/