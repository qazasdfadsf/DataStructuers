#include "init.h"
#define MaxSize 10
typedef struct 
{
    ElemType data[MaxSize];
    int front,rear;//队头队尾指针
    /*int size;//队列当前长度,不浪费存储空间的做法
      size=MaxSize;//队满条件
      int tag;//最近进行的是删除0/插入1
      front==rear&&tag==1;//队满条件
      front==rear&&tag==0;//队空条件
    */
}SqQueue;//队列元素个数  (rear+MaxSize-front)%MaxSize
void InitQueue(SqQueue &Q)
{
    Q.rear=Q.front=0;

    // Q.tag=0;
    // size=0;
}
bool isEmpty(SqQueue Q)
{
    if(Q.rear==Q.front)
    //(Q.rear+1)%MaxSize==Q.front队尾指针指向队尾元素
        return true;
    else
        return false;
}
bool EnQueue(SqQueue &Q,ElemType x)
{//入队
    if((Q.rear+1)%MaxSize==Q.front)
    {
        return false;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    // size++;
    // tag=1;
    return true;
}
bool DeQueue(SqQueue &Q,ElemType &x)
{//出队
    if(Q.rear==Q.front)
    {//队列为空
        return false;
    }
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;//队尾指针指向队尾下一个元素
    // size--；
    // tag=0;队空 front==rear&&tag=0
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