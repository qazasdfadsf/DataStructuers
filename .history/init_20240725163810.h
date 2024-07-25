#include<iostream>
using namespace std;
struct ElemType
{
    int value;
    // 重载 == 运算符
    bool operator==(const ElemType& other) const {
        return value == other.value;
    }
     bool operator!=(const ElemType& other) const {
        return value != other.value;
    }
};
//链队列=======================================================
// 定义链表节点结构体
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode;

// 定义链队列结构体
typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

// 函数声明
void InitQueue(LinkQueue &Q);
bool isEmpty(LinkQueue &Q);
void EnQueue(LinkQueue &Q, ElemType &x);
bool DeQueue(LinkQueue &Q, ElemType &x);