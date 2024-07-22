#include "init.h"
#define MaxSize 10
typedef struct
{
    ElemType data[MaxSize];
    int top;//栈顶指针
}SqStack;
void InitStack(SqStack &S)
{
    S.top=-1;
}
bool StackEmpty(SqStack S)
{
    if (S.top==-1)
        return true;
    else
        return false; 
}
bool Push(SqStack &S,ElemType x)
{//进栈
    if(S.top==MaxSize-1){
        return false;
    }
    S.data[++S.top]=x;//指针先加1，再入栈
    /*
    S.top=S.top+1;
    S.data[S.top]=x;
    */
    return true;
}
bool Pop(SqStack &S,ElemType &x){//bool Pop(SqStack &S,ElemType &x)
    if(S.top==-1){
        return false;
    }
    x=S.data[S.top--];//先出栈，指针再减1
    return true;
}
bool GetTop(SqStack S,int &x){//bool GetTop(SqStack S,ElemType &x)
    
}
int main(){
    SqStack S;
    InitStack(S);
    return 0;
}