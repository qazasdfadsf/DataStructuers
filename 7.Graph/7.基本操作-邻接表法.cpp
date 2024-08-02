#include "init.h"
#include "2.邻接表法.cpp"
void InitGraph(ALGraph *G)
{// 初始化图
    G->vexnum = 0;
    G->arcnum = 0;
    for (int i = 0; i < MaxVertexNum; i++) 
        G->vertices[i].first = NULL;
}
void InsertVertex(ALGraph *G, VertexType x) 
{// 在图G插入顶点x
    if (G->vexnum >= MaxVertexNum) 
    {
        printf("Vertex limit reached.\n");
        return;
    }
    G->vertices[G->vexnum].data = x;
    G->vertices[G->vexnum].first = NULL;
    G->vexnum++;
}
void DeleteVertex(ALGraph *G, int x) 
{// 从图G中删除顶点x
    if (x < 0 || x >= G->vexnum)
    {
        printf("Invalid vertex number.\n");
        return;
    }
    // 删除与该顶点相关的边
    for (int i = 0; i < G->vexnum; i++) 
    {
        ArcNode *prev = NULL;
        ArcNode *cur = G->vertices[i].first;
        while (cur) {
            if (cur->adjvex == x) 
            {
                if (prev) 
                    prev->next = cur->next;
                else 
                    G->vertices[i].first = cur->next;
                free(cur);
                G->arcnum--;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
    }
    // 删除顶点并调整顶点表
    for (int i = x; i < G->vexnum - 1; i++) 
    {
        G->vertices[i] = G->vertices[i + 1];
        ArcNode *cur = G->vertices[i].first;
        while (cur) 
        {
            if (cur->adjvex > x) 
                cur->adjvex--;
            cur = cur->next;
        }
    }
    G->vexnum--;
}
void AddEdge(ALGraph *G, int x, int y) 
{// 添加边
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum) 
    {
        printf("Invalid vertex number.\n");
        return;
    }
    ArcNode *newNode = (ArcNode *)malloc(sizeof(ArcNode));
    newNode->adjvex = y;
    newNode->next = G->vertices[x].first;
    G->vertices[x].first = newNode;
    G->arcnum++;
}
void RemoveEdge(ALGraph *G, int x, int y) 
{// 删除边
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum) 
    {
        printf("Invalid vertex number.\n");
        return;
    }
    ArcNode *prev = NULL;
    ArcNode *cur = G->vertices[x].first;
    while (cur) 
    {
        if (cur->adjvex == y) 
        {
            if (prev) 
                prev->next = cur->next;
            else 
                G->vertices[x].first = cur->next;
            free(cur);
            G->arcnum--;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
int FirstNeighbor(ALGraph *G, int x) 
{// 求图G中顶点x的第一个邻接点
    if (x < 0 || x >= G->vexnum) 
        return -1;
    if (G->vertices[x].first) 
        return G->vertices[x].first->adjvex;
    return -1;
}
int NextNeighbor(ALGraph *G, int x, int y) 
{// 求图G中顶点x相对于顶点y的下一个邻接点
    if (x < 0 || x >= G->vexnum)
        return -1;
    ArcNode *cur = G->vertices[x].first;
    while (cur) 
    {
        if (cur->adjvex == y && cur->next) 
            return cur->next->adjvex;
        cur = cur->next;
    }
    return -1;
}
int Get_edge_value(ALGraph *G, int x, int y) 
{// 获取图G中边(x, y)的权值
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum) 
    {
        printf("Invalid vertex number.\n");
        return -1;
    }
    ArcNode *cur = G->vertices[x].first;
    while (cur) 
    {
        if (cur->adjvex == y) 
        {
            // return cur->weight; // 如果有权值，返回权值
        }
        cur = cur->next;
    }
    return -1; // 如果没有找到边，返回-1
}
void Set_edge_value(ALGraph *G, int x, int y, int v) 
{// 设置图G中边(x, y)的权值
    if (x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum) 
    {
        printf("Invalid vertex number.\n");
        return;
    }
    ArcNode *cur = G->vertices[x].first;
    while (cur) 
    {
        if (cur->adjvex == y) 
        {
            // cur->weight = v; // 设置权值
            return;
        }
        cur = cur->next;
    }
    // 如果边不存在，添加新的边
    AddEdge(G, x, y);
    // G->vertices[x].first->weight = v; // 设置新边的权值
}