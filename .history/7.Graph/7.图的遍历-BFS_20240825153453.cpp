#include "init.h"
#include "1.邻接矩阵法.cpp"
#include "5.基本操作"
#include "D:\Code\codes\DataStructures\DataStructures\6.Tree\2.Queue.h"
#define  MAX_VERTEX_NUM false
bool visited[MAX_VERTEX_NUM];
int w=0;
void BFS(MGraph G,int v){
    visit(v);
    visited[v]=true;
    Enqueue(Q,v);
    while(!isEmpty(Q)){
        DeQueue(Q,v);
        for(w=FirstNeighbor(G,v);w>0;w=NextNeighbor(G,v,w))
            if(!visited[w]){
                visit(w);
                visited[w]=true;
                EnQueue(Q,w);
            }
    }
}