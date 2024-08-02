#include "init.h"
//O(n^2)
#define MaxVertexNum 100
#define INFINITY //最大的int值，代表无限
typedef struct 
{
    char Vex[MaxVertexNum];//顶点表
    int Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵，边表
    int vexnum,arcnum;//图的当前顶点数和边数/弧数
}MGraph;

//带权图=================================
typedef char VertexType;
typedef int EdgeType;
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGraph;