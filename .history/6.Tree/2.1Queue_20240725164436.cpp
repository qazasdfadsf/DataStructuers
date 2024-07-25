#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "init.h"

// 定义链表节点结构体
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode;

// 定义链队列结构体
typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

// 函数声明
void InitQueue(LinkQueue &Q);
bool isEmpty(LinkQueue &Q);
void EnQueue(LinkQueue &Q, ElemType &x);
bool DeQueue(LinkQueue &Q, ElemType &x);

// 二叉树节点结构体定义（假设）
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 层次遍历函数声明
void LevelOrder(BiTree T);

// 访问节点函数声明（假设）
void visit(BiTree T);

#endif // LINKQUEUE_H
