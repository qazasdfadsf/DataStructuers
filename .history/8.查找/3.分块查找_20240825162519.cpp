#include "init.h"
typedef struct
{//有序顺序表
    ElemType *elem;
    int TableLen;
}SSTable;
/*
分块查找
特点：块内无序 块间有序

*/
