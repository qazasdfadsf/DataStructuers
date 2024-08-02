#include "init.h"
//无向图
//边
struct EdgeNode 
{
    int ivex, jvex; //该边依附的两个顶点的位置
    EdgeNode *ilink, *jlink; //分别指向依附于这两个顶点的下一条边
};
//顶点
struct VertexNode 
{
    int data; //顶点信息
    EdgeNode *firstEdge; //指向第一条依附于该顶点的边
};
//图
struct AMLGraph 
{
    VertexNode *vexArr; //顶点数组
    int vexNum, edgeNum; //图的顶点数和边数
};

