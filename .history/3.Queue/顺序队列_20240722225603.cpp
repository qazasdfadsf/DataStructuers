#include "init.h"
#define MaxSize 10
typedef struct 
{
    ElemType data[MaxSize];
    int front,rear;//队头队尾指针
    //int size;不浪费存储空间的做法
}SqQueue;
void InitQueue(SqQueue &Q)
{
    Q.rear=Q.front=0;
}
bool isEmpty(SqQueue Q)
{
    if(Q.rear==Q.front){
        return true;
    }else{
        return false;
    }
}
bool EnQueue(SqQueue &Q,ElemType x)
{//入队
    if((Q.rear+1)%MaxSize==Q.front)
    {
        return false;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}
bool DeQueue(SqQueue &Q,ElemType &x)
{//出队
    if(Q.rear==Q.front)
    {//队列为空
        return false;
    }
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}
bool GetHead(SqQueue Q,ElemType &x)
{
    //获取队头元素
    if(Q.rear==Q.front)
    {
        return false;
    }
    x=Q.data[Q.front];
    return true;
}
//队列元素个数  (rear+MaxSize-front)%MaxSize