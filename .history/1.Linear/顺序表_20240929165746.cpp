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
ElemType GetElem(SqList L, int i){
    return L.data[i];
}
bool ListInsert(SqList &L,int i,ElemType e){
    if (L.length+1!=MaxSize||i<=L.length||i>=0)
    {
        for (int j = L.length; j> i; j--)
        {
            L.data[j+1]=L.data[j];
        }
        L.data[i]=e;
    }
    else    return false;
}
bool ListDelete(SqList &L,int i,ElemType &e){
    if (i<=L.length||i>=0)
    {
        e=L.data[i];
        for (int j = i; j <L.length+1;j++){
            L.data[j]=L.data[j+1];
        }
        return true;
    }
    else    return false;
}
void PrintList(SqList L){
    for (int i = 0; i < L.length; i++)
    {
        std::cout<<L.data[i] <<std::endl;
    }
    
}
