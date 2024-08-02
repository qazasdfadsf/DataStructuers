#include "init.h"

// 定义边结点结构体
struct EdgeNode 
{
    int ivex, jvex; // 该边依附的两个顶点的位置
    EdgeNode *ilink, *jlink; // 分别指向依附于这两个顶点的下一条边
};

// 定义顶点结点结构体
struct VertexNode 
{
    int data; // 顶点信息
    EdgeNode *firstEdge; // 指向第一条依附于该顶点的边
};

// 定义图结构体
struct AMLGraph 
{
    VertexNode *vexArr; // 顶点数组
    int vexNum, edgeNum; // 图的顶点数和边数
};

