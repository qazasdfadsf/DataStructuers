#include "init.h"
#define MaxVertexNum 100

typedef int VertexType; // 定义顶点的类型

typedef struct {
    VertexType Vex[MaxVertexNum]; // 顶点数组
    int Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵
    int vexnum; // 当前顶点数
    int arcnum; // 当前边数
} Graph;
bool Adjacent(Graph *M, int x, int y) 
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
void InsertVertex(Graph *G, VertexType x) 
{//在图G插入顶点x
    if (G->vexnum >= MaxVertexNum)// 检查是否达到顶点上限
    {
        printf("Vertex limit reached.\n");
        return;
    }
    // 插入顶点到顶点表
    G->Vex[G->vexnum] = x;
    for (int i = 0; i <= G->vexnum; i++)// 初始化新顶点的邻接矩阵行和列
    {
        G->Edge[G->vexnum][i] = 0;
        G->Edge[i][G->vexnum] = 0;
    }
    // 增加顶点数量
    G->vexnum++;
}
void DeleteVertex(Graph *G, int x) 
{// 从图G中删除顶点x
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum) 
    {
        printf("Invalid vertex number.\n");
        return;
    }
    // 删除顶点并调整顶点表和邻接矩阵
    for (int i = x; i < G->vexnum - 1; i++) 
    {
        G->Vex[i] = G->Vex[i + 1];
        for (int j = 0; j < G->vexnum; j++) 
        {
            G->Edge[i][j] = G->Edge[i + 1][j];
            G->Edge[j][i] = G->Edge[j][i + 1];
        }
    }
    G->vexnum--;// 减少顶点数量
}

void AddEdge(Graph *G, int x, int y) 
{//添加边
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum) 
    {
        printf("Invalid vertex number.\n");
        return;
    }
    // 添加边并增加边的数量
    if (G->Edge[x][y] == 0)
    {
        G->Edge[x][y] = 1;
        G->arcnum++;
    }
}
void RemoveEdge(Graph *G, int x, int y) 
{//删除边
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum) 
    {
        printf("Invalid vertex number.\n");
        return;
    }
    // 删除边并减少边的数量
    if (G->Edge[x][y] != 0) 
    {
        G->Edge[x][y] = 0;
        G->arcnum--;
    }
}
int FirstNeighbor(Graph *G, int x) 
{//求图G中顶点x的第一个邻接点
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum) 
    {
        return -1;
    }
    // 查找第一个邻接点
    for (int i = 0; i < G->vexnum; i++) 
    {
        if (G->Edge[x][i] != 0) 
            return i;
    }
    return -1;
}
int NextNeighbor(Graph *G, int x, int y) 
{// 求图G中顶点x相对于顶点y的下一个邻接点
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum)
        return -1;
    // 查找下一个邻接点
    for (int i = y + 1; i < G->vexnum; i++) 
    {
        if (G->Edge[x][i] != 0)
            return i;
    }
    return -1;
}
int Get_edge_value(Graph *G, int x, int y) 
{//获取图G中边(x, y)的权值
    // 检查顶点编号是否有效
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum)
    {
        printf("Invalid vertex number.\n");
        return -1;
    }
    // 返回边的权值
    return G->Edge[x][y];
}
void Set_edge_value(Graph *G, int x, int y, int v) 
{// 设置图G中边(x, y)的权值
    // 检查顶点编号是否有效
    if(x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum) 
    {
        printf("Invalid vertex number.\n");
        return;
    }
    // 设置边的权值
    G->Edge[x][y] = v;
}