#include "init.h"
//  空间复杂度O(|V|^2)  适合存储稠密图
#define MaxVertexNum 100
//无向图or有向图    求度O(|V|)
typedef struct 
{
    ElemType Vex[MaxVertexNum];//顶点表
    int Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵，边表   可以用bool类型
    int vexnum,arcnum;//图的当前顶点数和边数/弧数
}MGraph;//可以利用对称矩阵压缩存储

//带权图=================================
#define INFINITY //最大的int值，代表无限
typedef char VertexType;
typedef int EdgeType;
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGraph;