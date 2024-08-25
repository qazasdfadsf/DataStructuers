#include "init.h"
#define MaxVertexNum 100

typedef int VertexType; // 定义顶点的类型

typedef struct {
    VertexType Vex[MaxVertexNum]; // 顶点数组
    int Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵
    int vexnum; // 当前顶点数
    int arcnum; // 当前边数
} Graph;
