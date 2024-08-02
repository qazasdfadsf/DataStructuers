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
    if (x < 0 || x >= G->vexnum)
    {
        printf("Invalid vertex number.\n");
        return;
    }
    printf("The neighbors of vertex %d are:\n", x);
    for (int i = 0; i < G->vexnum; i++) 
    {
        if (G->Edge[x][i] != 0) 
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}
void InsertVertex(MGraph *G, VertexType x) 
{//在图G插入顶点x
    if (G->vexnum >= MaxVertexNum)// 检查是否达到顶点上限
    {
        printf("Vertex limit reached.\n");
        return;
    }
    // 插入顶点到顶点表
    G->Vex[G->vexnum] = x;
    // 初始化新顶点的邻接矩阵行和列
    for (int i = 0; i <= G->vexnum; i++) {
        G->Edge[G->vexnum][i] = 0;
        G->Edge[i][G->vexnum] = 0;
    }
    // 增加顶点数量
    G->vexnum++;
}

// 从图G中删除顶点x
void DeleteVertex(MGraph *G, int x) {
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum) {
        printf("Invalid vertex number.\n");
        return;
    }
    // 删除顶点并调整顶点表和邻接矩阵
    for (int i = x; i < G->vexnum - 1; i++) {
        G->Vex[i] = G->Vex[i + 1];
        for (int j = 0; j < G->vexnum; j++) {
            G->Edge[i][j] = G->Edge[i + 1][j];
            G->Edge[j][i] = G->Edge[j][i + 1];
        }
    }
    // 减少顶点数量
    G->vexnum--;
}

// 若边不存在，则添加该边
void AddEdge(MGraph *G, int x, int y) {
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum) {
        printf("Invalid vertex number.\n");
        return;
    }
    // 添加边并增加边的数量
    if (G->Edge[x][y] == 0) {
        G->Edge[x][y] = 1;
        G->arcnum++;
    }
}

// 若无向边或有向边存在，则删除
void RemoveEdge(MGraph *G, int x, int y) {
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum) {
        printf("Invalid vertex number.\n");
        return;
    }
    // 删除边并减少边的数量
    if (G->Edge[x][y] != 0) {
        G->Edge[x][y] = 0;
        G->arcnum--;
    }
}

// 求图G中顶点x的第一个邻接点，有则返回顶点号，若没有则返回-1
int FirstNeighbor(MGraph *G, int x) {
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum) {
        return -1;
    }
    // 查找第一个邻接点
    for (int i = 0; i < G->vexnum; i++) {
        if (G->Edge[x][i] != 0) {
            return i;
        }
    }
    return -1;
}

// 求图G中顶点x相对于顶点y的下一个邻接点
int NextNeighbor(MGraph *G, int x, int y) {
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum) {
        return -1;
    }
    // 查找下一个邻接点
    for (int i = y + 1; i < G->vexnum; i++) {
        if (G->Edge[x][i] != 0) {
            return i;
        }
    }
    return -1;
}

// 获取图G中边(x, y)的权值
int Get_edge_value(MGraph *G, int x, int y) {
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum) {
        printf("Invalid vertex number.\n");
        return -1;
    }
    // 返回边的权值
    return G->Edge[x][y];
}

// 设置图G中边(x, y)的权值
void Set_edge_value(MGraph *G, int x, int y, int v) {
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum) {
        printf("Invalid vertex number.\n");
        return;
    }
    // 设置边的权值
    G->Edge[x][y] = v;
}

//邻接表法
