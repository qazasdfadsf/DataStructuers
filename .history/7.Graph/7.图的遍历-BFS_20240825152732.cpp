#include "init.h"
#include "1.邻接矩阵法.cpp"
#include "D:\Code\codes\DataStructures\DataStructures\6.Tree\2.Queue.h"
#define  MAX_VERTEX_NUM false
bool visited[MAX_VERTEX_NUM];
void BFS(Graph G,int v){
    visit(v);
    visited[v]=true;
    Enqueue(Q,v);
    while(!isEmpty(Q)){
        DeQueue(Q,v);
        for(w=FirstNeighbor(G,v))
    }
}