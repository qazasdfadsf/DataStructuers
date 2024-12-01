#include "init.h"
using namespace std;
#define InitSize 20
typedef struct SeqList
{
    ElemType *data;
    int length,MaxSize;
};
void InitList(SeqList &L){
    L.length=0;
    L.data=new ElemType[InitSize];
    L.MaxSize=InitSize;
}
void IncreaseSize(SeqList &L,int len){
    ElemType *p=L.data;
    L.data=new ElemType[len+L.MaxSize];
    for (int i = 0; i < L.length; i++)
    {
        L.data[i]=p[i];
    }
    L.length+=len;
    delete p;
}