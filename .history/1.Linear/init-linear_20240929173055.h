#include "init.h"
#define MaxSize 20
typedef struct 
{
    ElemType data[MaxSize];
    int length;
}SqList;//Sequence List
void InitList(SqList &L);
int Length(SqList L);
int LocateElem(SqList &L,ElemType e);
ElemType GetElem(SqList L, int i);
bool ListInsert(SqList &L,int i,ElemType e);
bool ListDelete(SqList &L,int i,ElemType &e);
void PrintList(SqList L);
bool Empty(SqList L);
void DestroyList(SqList &L);