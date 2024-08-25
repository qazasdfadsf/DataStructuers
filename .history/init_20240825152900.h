#ifndef MY_HEADER_H // 防止重复包含
#define MY_HEADER_H

#include <iostream> // 包含输入输出流头文件
using namespace std;

// 定义元素类型结构体
struct ElemType {
    int value; // 元素的值

    // 重载 == 运算符，用于比较两个 ElemType 是否相等
    bool operator==(const ElemType& other) const {
        return value == other.value;
    }

    // 重载 != 运算符，用于比较两个 ElemType 是否不相等
    bool operator!=(const ElemType& other) const {
        return value != other.value;
    }
};

// 顶点类型结构体，用于图的表示
struct VertexType {
    int id; // 顶点的ID
};

bool visit(int Edge){
    printf("v");
}
#define MaxVertexNum 100
typedef struct 
{
    ElemType Vex[MaxVertexNum];//顶点表
    int Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵，边表   可以用bool类型
    int vexnum,arcnum;//图的当前顶点数和边数/弧数
}Graph;//可以利用对称矩阵压缩存储(0/1)
void InitGraph(Graph *G) {
    G->vexnum = 0;
    for (int i = 0; i < MaxVertexNum; i++) {
        for (int j = 0; j < MaxVertexNum; j++) {
            G->Edge[i][j] = 0;
        }
    }
}

#endif // MY_HEADER_H