#include "init.h"
#include "1.邻接矩阵法.cpp"
#include "2.邻接表法.cpp"

//邻接矩阵法
    //无向图
bool Adjacent(MGraph *M, int x, int y) 
{//判断两个顶点是否相邻
    // 检查边界条件，确保 x 和 y 是有效的顶点编号
    if (x < 0 || x >= M->vexnum || y < 0 || y >= M->vexnum)
        return false;
    // 返回邻接矩阵中相应位置的值，判断是否相邻
    return M->Edge[x][y] != 0;
}
void Neighbors(MGraph *G, int x) 
{//列出图 G 中结点 x 所邻接的所有边
    // 检查边界条件，确保 x 是有效的顶点编号
    if (x < 0 || x >= G->vexnum) {
        printf("Invalid vertex number.\n");
        return;
    }
    printf("The neighbors of vertex %d are:\n", x);
    for (int i = 0; i < G->vexnum; i++) {
        if (G->Edge[x][i] != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

//邻接表法
