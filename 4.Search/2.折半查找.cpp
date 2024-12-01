#include "init.h"
typedef struct
{//有序顺序表
    ElemType *elem;
    int TableLen;
}SSTable;
int Binary_Search(SSTable L, ElemType key)
{
    int low=0,high=L.TableLen-1,mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        //升序
        if(L.elem[mid]==key)
            return mid;
        else if(L.elem[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}