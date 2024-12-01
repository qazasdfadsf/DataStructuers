#include "init.h"
#define MaxSize 10
typedef struct
{
    ElemType data[MaxSize];
    int top0;//0号栈 栈顶指针
    int top1;//1号栈 栈顶指针
}ShStack;
void InitStack(ShStack &S)
{
    S.top0=-1;
    S.top1=MaxSize;
}
//栈满  top0+1==top1;