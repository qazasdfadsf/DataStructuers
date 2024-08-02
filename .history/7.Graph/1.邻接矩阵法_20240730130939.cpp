#include "init.h"
#define MaxVertexNum 100
typedef struct 
{
    char Vex[MaxVertexNum];//定点表
    int Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGraph;
