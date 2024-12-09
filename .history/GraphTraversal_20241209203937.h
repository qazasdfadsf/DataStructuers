#ifndef GRAPH_TRAVERSAL_H
#define GRAPH_TRAVERSAL_H

#include <stdbool.h> // 提供 bool 类型支持
#include "Queue.h"   // 假设已实现队列的功能
#include "Graph.h"   // 假设图的结构在 Graph.h 中定义

#define MAX_VERTEX_NUM 100 // 最大顶点数

// 全局变量
extern bool visited[MAX_VERTEX_NUM]; // 用于记录顶点是否被访问

// 图的结构定义（假设 Graph.h 中有具体定义）
typedef struct {
    int vexnum;                              // 图的顶点数
    int adj[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
} MGraph;

// 函数声明

/**
 * @brief 访问图中的某个顶点
 * @param v 顶点编号
 */
void visit(int v);

/**
 * @brief 获取图中顶点 v 的第一个邻接点
 * @param G 图
 * @param v 顶点编号
 * @return 返回第一个邻接点的编号，若无邻接点返回 -1
 */
int FirstNeighbor(MGraph G, int v);

/**
 * @brief 获取图中顶点 v 相对于 w 的下一个邻接点
 * @param G 图
 * @param v 顶点编号
 * @param w 当前邻接点编号
 * @return 返回下一个邻接点的编号，若无更多邻接点返回 -1
 */
int NextNeighbor(MGraph G, int v, int w);

/**
 * @brief 广度优先遍历单个连通分量
 * @param G 图
 * @param v 起始顶点编号
 */
void BFS(MGraph G, int v);

/**
 * @brief 广度优先遍历整个图
 * @param G 图
 */
void BFSTraverse(MGraph G);

/**
 * @brief 深度优先遍历单个连通分量
 * @param G 图
 * @param v 起始顶点编号
 */
void DFS(MGraph G, int v);

/**
 * @brief 深度优先遍历整个图
 * @param G 图
 */
void DFSTraverse(MGraph G);

#endif // GRAPH_TRAVERSAL_H
