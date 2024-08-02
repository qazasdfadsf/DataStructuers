#include "init.h"
//边or弧
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
}ArcNode;
//顶点
typedef struct VNode
{
    VertexType data;
    ArcNode *first;
}VNode,AdjList[MaxVertexNum];
//用邻接表存储的图
typedef struct 
{
    AdjList vertices;
    int vexnm,arcnum;
}ALGraph;
