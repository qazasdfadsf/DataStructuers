#include "init.h"
#include "1.邻接矩阵法.cpp"
#include "2.邻接表法.cpp"

//邻接矩阵法
    //无向图
bool Adjacent(MGraph *M, int x, int y) 
{
    // 检查边界条件，确保 x 和 y 是有效的顶点编号
    if (x < 0 || x >= M->vexnum || y < 0 || y >= M->vexnum)
        return false;
    // 返回邻接矩阵中相应位置的值，判断是否相邻
    return M->Edge[x][y] != 0;
}
//邻接表法
