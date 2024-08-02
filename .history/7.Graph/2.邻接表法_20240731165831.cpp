#include "init.h"
//顺序存储+链式存储
#define MaxVertexNum 100
//顶点
typedef struct VNode
{
    VertexType data;//顶点信息
    ArcNode *first;//第一条边(弧)
}VNode,AdjList[MaxVertexNum];
//边or弧
typedef struct ArcNode
{
    int adjvex;//边(弧)指向哪一个节点
    struct ArcNode *next;
    //InfoType info 权值
}ArcNode;
//用邻接表存储的图
typedef struct 
{
    AdjList vertices;
    int vexnm,arcnum;
}ALGraph;
