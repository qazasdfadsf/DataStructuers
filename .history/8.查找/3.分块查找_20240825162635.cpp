#include "init.h"
typedef struct
{//有序顺序表
    ElemType maxValue;
    int TableLen;
}SSTable;
/*
分块查找
特点：块内无序 块间有序

*/
typedef struct 
{
    ElemType maxValue;
    int low,high;
}Index;
ElemType List[100];