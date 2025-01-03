#include "init.h"
#include "1.邻接矩阵法.cpp"
#include "Graph.h"
//广度优先遍历
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
//BFS   final
bool visited[MAX_VERTEX_NUM];
void BFSTraverse(MGraph G)
{//O(|V|^2)
    for(i=0;i<G.vexnum;i++)
        visited[i]=false;
    InitQueue(Q);
    for(i=0;i<G.vexnum;++i){
        if(!visited[i])
            BFS(G,i);
    }
}
//深度优先遍历
bool visited[MAX_VERTEX_NUM];
void DFS(MGraph G,int v){
    visit(v);
    visited[v]=true;
    for(w-FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
        if(!visited[w])
            DFS(G,w);
    }
}
//DFS   final
void DFSTraverse(MGraph G){
    for(v=0;v<G.vexnum;++v)
        visited[v]=false;
    for(v=0;v<G.vexnum;++v)
    {
        if(!visited[v])
            DFS(G,v);
    }
}