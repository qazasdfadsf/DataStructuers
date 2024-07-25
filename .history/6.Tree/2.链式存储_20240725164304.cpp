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
//层次遍历
typedef struct LinkNode
{
    BiTNode* data;
    struct LinkNode *next;
} LinkNode;
// 定义链队列结构体
typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new LinkNode;
    Q.front->next=NULL;
}
bool isEmpty(LinkQueue &Q)
{
    if (Q.front==Q.rear)
        return true;
    else
        return false;
}
void EnQueue(LinkQueue &Q,BiTNode &x)
{//入队
    LinkNode *s=new LinkNode;
    s->data=x;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}
bool DeQueue(LinkQueue &Q,BiTNode &x)
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
