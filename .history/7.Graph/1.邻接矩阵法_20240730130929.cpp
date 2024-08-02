#include "init.h"
#define MaxVertexNum 100
typedef struct 
{
    char Vex[MaxVertexNum];
    int Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGraph;
