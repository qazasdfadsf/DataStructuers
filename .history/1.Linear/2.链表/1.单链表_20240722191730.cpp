#include "init.h"
typedef struct LNode
{
    ElemType data;
    struct LNode* next;//LinkList L;    ==  LNode* L;
}LNode,*LinkList;
/*等价于
struct LNode{
    ElemType data;
    struct LNode* next;
};
typedef struct LNode LNode;
typedef struct LNode* LinkList;
*/
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
    L->next=NULL;
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
    if(L->next==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Length(LinkList L)
{//求表长    O(n)
    int len=0;
    LNode* p=L;
    while (p->next!=NULL)
    {
        p=p->next;
        len++;
    }
    return len;
}
LNode *GetElem(LinkList L,int i)
{//按位查找  O(n)
    if(i<0)
    {
        return NULL;
    }
    LNode *p;
    int j=0;
    p=L;
    while(p!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;//找不到返回NULL
}
LNode* LocateElem(LinkList L,ElemType e)
{//按值查找  O(n)
    LNode* p=L->next;
    while (p!=NULL&&p->data!=e)
    {
        p=p->next;
    }
    return p;//找不到返回NULL
}
bool InsertNextNode(LNode*p,ElemType e)
{//后插操作 O(1)
    if(p==NULL)
    {
        return false;
    }
    LNode* s=new LNode;
    if(s==NULL)
    {//内存分配失败
        return false;
    }
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
bool InsertPriorNode(LNode* p,ElemType e)
{//前插操作  O(1)
    if(p==NULL)
    {
        return false;
    }
    LNode *s=new LNode;
    if(s==NULL)
    {
        return false;
    }
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}
bool ListInsert(LinkList &L,int i,ElemType e)
{//按位插入  O(n)
    if(i<1)
    {
        return false;
    }
    else
    {
        LNode *p=GetElem(L,i-1);
        /*
        LNode *p;
        int j=0;//当前p指向的是第几个节点
        p=L;
        while(p!=NULL&&j<i-1)//找到第i-1个节点
        {
            p=p->next;
            j++;
        }
        */
        return InsertNextNode(p,e);
        /*   
        if (p==NULL)    //i值不合法
        {
            return false;
        }
        LNode* s=new LNode;
        //LNode* s=(LNode*)malloc(sizeof(LNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
        */
    }
}
bool nhListInsert(LinkList &L,int i,ElemType e)
{//没有头节点的按序插入  O(n)
    if(i<1)
    {
        return false;
    }
    if(i==1)
    {
        LNode *s=new LNode;
        s->data=e;
        s->next=L;
        L=s;
        return true;
    }
    // LNode *p=GetElem(L,i-1);
    LNode *p;
    int j=1;//当前p指向的是第几个节点，不同与有头结点
    p=L;
    while(p!=NULL&&j<i-1)//找到第i-1个节点
    {
        p=p->next;
        j++;
    }
    return InsertNextNode(p,e);
    /*
    if (p==NULL)    //i值不合法
    {
        return false;
    }
    LNode* s=new LNode;
    //LNode* s=(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
    */
}
bool ListDelete(LinkList &L,int i,ElemType &e)
{//删除节点  O(n)
    if(i<1)
    {
        return false;
    }
    LNode *p=GetElem(L,i-1);
    /*
    LNode* p;
    int j=0;
    p=L;
    while (p!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }
    */
    if (p==NULL||p->next==NULL)
    {
        return false;
    }
    LNode* q=p->next;
    e=q->data;
    p->next=q->next;
    delete q;
    return true;
}
bool Delete(LNode* p)
{//删除指定节点  O(1)
    if(p==NULL)
    {
        return false;
    }
    LNode*q=p->next;
    p->data=p->next->data;//p->next->data=NULL可能有这种情况
    p->next=q->next;
    delete q;
    return true;
}
LinkList List_HeadInsert(LinkList &L)
{//头插法   列表逆置
    LNode *s;
    ElemType x;
    L=new LNode;//L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while(x.value!=9999)
    {
        s=new LNode;
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}
LinkList List_TailInsert(LinkList &L)
{//尾插法
    ElemType x;
    L=new LNode;
    LNode* s;
    LNode*r=L;//表尾指针
    scanf("%d",&x);
    while (x.value!=9999)
    {//后插
        s=new LNode;
        s->data=x;
        r->next=s;
        r=s;//指向新的表尾节点
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}
int main(){
    return 0;
}