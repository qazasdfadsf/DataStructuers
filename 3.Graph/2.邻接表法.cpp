#include "init.h"
//顺序存储+链式存储 适用于存储稀疏图
// 空间复杂度   无向图O(|V|+2E) 有向图O(|V|+E)  
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
    struct ArcNode *next;//指向下一条边(弧)的指针
    //InfoType info 权值
}ArcNode;
//用邻接表存储的图
typedef struct 
{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
