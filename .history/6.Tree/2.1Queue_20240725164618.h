#include <stdio.h>
#include <stdlib.h>
#include "level_order_traversal.h"

// Initialize the queue
void InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front) {
        exit(1); // Memory allocation failed
    }
    Q->front->next = NULL;
}

// Check if the queue is empty
bool isEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

// Enqueue operation
void EnQueue(LinkQueue *Q, BiTree e) {
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s) {
        exit(1); // Memory allocation failed
    }
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
}

// Dequeue operation
bool DeQueue(LinkQueue *Q, BiTree *e) {
    if (Q->front == Q->rear) {
        return false; // Queue is empty
    }
    QueuePtr p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return true;
}

// Visit function (can be customized)
void visit(BiTree p) {
    printf("%d ", p->data); // Print the node's data
}

// Level order traversal
void LevelOrder(BiTree T) {
    LinkQueue Q;
    InitQueue(&Q);
    BiTree p;
    EnQueue(&Q, T);
    while (!isEmpty(Q)) {
        DeQueue(&Q, &p);
        visit(p);
        if (p->lchild != NULL) {
            EnQueue(&Q, p->lchild);
        }
        if (p->rchild != NULL) {
            EnQueue(&Q, p->rchild);
        }
    }
}
