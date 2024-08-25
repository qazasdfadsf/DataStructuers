#include "init.h"
typedef struct{
    ElemType *elem;
    int TableLen;
}SSTable;
//顺序查找
int Search_Seq(SSTable ST,ElemType key){
    int i;
    for(i=0;i<ST.TableLen && ST.elem[i]!=key;++i);
    return i;
}