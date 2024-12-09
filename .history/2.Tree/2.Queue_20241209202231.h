#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点类型
typedef struct BiTNode {
    int data; // 假设树的数据类型是 int
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 队列节点定义
typedef struct QNode {
    BiTree data;          // 存储树节点的指针
    struct QNode *next;   // 指向下一个队列节点
} QNode, *QueuePtr;

// 队列结构定义
typedef struct {
    QueuePtr front;       // 队头指针
    QueuePtr rear;        // 队尾指针
} LinkQueue;

// 队列的函数声明
void InitQueue(LinkQueue &Q);
bool isEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q, BiTree e);
bool DeQueue(LinkQueue &Q, BiTree &e);

#endif
