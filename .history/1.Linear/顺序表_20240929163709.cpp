#include "init.h"
#define MaxSize 20
typedef struct SqList
{
    ElemType data[MaxSize];
    int length;
};
void InitList(SqList &L){
    L.length=0;
}
int Length(SqList L){
    return L.length;
}
int LocateElem(SqList &L,ElemType e){
    int i;
    for (int i = 0; i < MaxSize; i++)
    {
        if (L.data[i]==e)
        {
            return i;
        }
    }
}
