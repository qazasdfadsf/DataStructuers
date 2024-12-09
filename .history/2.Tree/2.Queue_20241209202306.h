#ifndef LEVEL_ORDER_TRAVERSAL_H
#define LEVEL_ORDER_TRAVERSAL_H

// 二叉树节点的定义
typedef struct BiTNode {
    int data; // 你可以根据需要更改数据类型
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 队列节点的定义
typedef struct QNode {
    BiTree data;
    struct QNode *next;
} QNode, *QueuePtr;

// 队列结构的定义
typedef struct {
    QueuePtr front, rear;
} LinkQueue;

// 函数声明
void InitQueue(LinkQueue *Q); // 初始化队列
bool isEmpty(LinkQueue Q); // 检查队列是否为空
void EnQueue(LinkQueue *Q, BiTree e); // 入队操作
bool DeQueue(LinkQueue *Q, BiTree *e); // 出队操作
void visit(BiTree p); // 访问节点（可以根据需要定制）
void LevelOrder(BiTree T); // 层次遍历函数

#endif // LEVEL_ORDER_TRAVERSAL_H
