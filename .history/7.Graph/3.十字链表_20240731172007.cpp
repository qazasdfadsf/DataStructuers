#include "init.h"


// 定义边结点结构体
struct ArcNode 
{
    int tailVex; // 弧尾顶点位置
    int headVex; // 弧头顶点位置
    ArcNode *hlink; // 指向下一条入边的指针
    ArcNode *tlink; // 指向下一条出边的指针
};
// 定义顶点结点结构体
struct VNode 
{
    int data; // 顶点信息
    ArcNode *firstIn; // 指向第一条入边的指针
    ArcNode *firstOut; // 指向第一条出边的指针
};
// 定义图结构体
struct OLGraph 
{
    VNode *xList; // 顶点数组
    int vexNum, arcNum; // 图的顶点数和边数
};
