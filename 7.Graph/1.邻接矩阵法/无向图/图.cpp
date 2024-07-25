#include<iostream>
using namespace std;
//无向图/有向图O(|v|^2)
#define MaxVertexNum 100
typedef struct 
{
    char Vex[MaxVertexNum];
    int Edge[MaxVertexNum][MaxVertexNum];//bool
    int vexnum,arcnum;
}MGraph;
