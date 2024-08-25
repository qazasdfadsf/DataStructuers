#include "init.h"
typedef struct
{//顺序表
    ElemType *elem;
    int TableLen;
}SSTable;
int Binary_Search(SSTable L, ElemType key)
{
    int low=0,high=L.TableLen-1,mid;
    
}