#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 100 // 最大顶点数

// 图的结构定义
typedef struct {
    int vexnum;                              // 顶点数
    int arcnum;                              // 边数
    int adj[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
} MGraph;

// 队列节点的定义
typedef struct QueueNode {
    int data;                 // 存储顶点编号
    struct QueueNode *next;   // 指向下一个节点
} QueueNode, *QueuePtr;

// 队列结构的定义
typedef struct {
    QueuePtr front, rear;     // 队头和队尾指针
} LinkQueue;

// 全局变量
bool visited[MAX_VERTEX_NUM]; // 记录顶点是否访问过

// 队列操作函数

void InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QueueNode));
    if (!Q->front) {
        printf("内存分配失败！\n");
        exit(1);
    }
    Q->front->next = NULL;
}

bool isEmpty(LinkQueue *Q) {
    return Q->front == Q->rear;
}

void EnQueue(LinkQueue *Q, int elem) {
    QueuePtr newNode = (QueuePtr)malloc(sizeof(QueueNode));
    if (!newNode) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = elem;
    newNode->next = NULL;
    Q->rear->next = newNode;
    Q->rear = newNode;
}

bool DeQueue(LinkQueue *Q, int *elem) {
    if (isEmpty(Q)) {
        return false;
    }
    QueuePtr temp = Q->front->next;
    *elem = temp->data;
    Q->front->next = temp->next;
    if (Q->rear == temp) {
        Q->rear = Q->front;
    }
    free(temp);
    return true;
}

// 图操作函数

void CreateGraph(MGraph *G) {
    printf("请输入顶点数和边数：\n");
    scanf("%d %d", &G->vexnum, &G->arcnum);
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            G->adj[i][j] = 0; // 初始化邻接矩阵为 0
        }
    }
    printf("请输入每条边的两个顶点（如：0 1 表示顶点 0 和顶点 1 相连）：\n");
    for (int k = 0; k < G->arcnum; k++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        G->adj[v1][v2] = 1; // 无向图两边都标记
        G->adj[v2][v1] = 1;
    }
}

int FirstNeighbor(MGraph G, int v) {
    for (int i = 0; i < G.vexnum; i++) {
        if (G.adj[v][i] == 1) {
            return i;
        }
    }
    return -1; // 无邻接点
}

int NextNeighbor(MGraph G, int v, int w) {
    for (int i = w + 1; i < G.vexnum; i++) {
        if (G.adj[v][i] == 1) {
            return i;
        }
    }
    return -1; // 无更多邻接点
}

void visit(int v) {
    printf("访问顶点 %d\n", v);
}

// BFS 和 DFS 操作

void BFS(MGraph G, int v) {
    LinkQueue Q;
    InitQueue(&Q);
    visit(v);
    visited[v] = true;
    EnQueue(&Q, v);
    while (!isEmpty(&Q)) {
        DeQueue(&Q, &v);
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                visit(w);
                visited[w] = true;
                EnQueue(&Q, w);
            }
        }
    }
}

void BFSTraverse(MGraph G) {
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            BFS(G, i);
        }
    }
}

void DFS(MGraph G, int v) {
    visit(v);
    visited[v] = true;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

void DFSTraverse(MGraph G) {
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}

// 主函数
int main() {
    MGraph G;
    CreateGraph(&G);

    printf("广度优先遍历结果：\n");
    BFSTraverse(G);

    printf("深度优先遍历结果：\n");
    DFSTraverse(G);

    return 0;
}
