#include "init.h"
typedef struct
{//顺序表
    ElemType *elem;
    int TableLen;
}SSTable;
int Search_Seq(SSTable ST,ElemType key)
{//顺序查找 ASL=(n+1)/2 O(n)
    int i;
    for(i=0;i<ST.TableLen && ST.elem[i]!=key;++i);
    return i==ST.TableLen? -1:i;
}
        