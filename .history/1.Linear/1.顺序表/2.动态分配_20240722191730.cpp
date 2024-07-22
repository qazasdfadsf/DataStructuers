#include "init.h"
#define InitSize 10
typedef struct{
    ElemType *data;
    int MaxSize;
    int length;
}SeqList;
void InitList(SeqList &L){
    L.data=new ElemType[InitSize];
    //L.data=(ElemType *)malloc(InitSize*sizeof(ElemType));
    L.length=0;
    L.MaxSize=InitSize;
}
void IncreaseSize(SeqList &L,int len)
{//动态增加数组长度
    ElemType *p=L.data;
    L.data= new ElemType[L.MaxSize + len];
    // (ElemType *)malloc((L.MaxSize+len)*sizeof(ElemType))
    for(int i=0;i<L.length;i++)
    {
        L.data[i]=p[i];
    }
    L.MaxSize=L.MaxSize+len;
    delete p;
    //free(p);
}
ElemType GetElem(SeqList L, int i)
{//按位查找 O(1)
    return L.data[i - 1];
}
int LocateElem(SeqList &L,ElemType e)
{//按值查找  O(n)
    int i;
    for(i=0;i<L.length;i++)
    {
        if(L.data[i]==e)
        {
            return i+1;
        }
    }
    return 0;
}

int main(){
    SeqList L;
    InitList(L);
    IncreaseSize(L,5);
    for(int i=0;i<L.MaxSize;i++){
        L.data[i].value=i;
        L.length++;
        cout<<L.data[i].value<<endl;
    }
    cout<<"ok"<<endl;
    cout<<L.length;
    return 0;
}