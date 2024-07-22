#include "init.h"
typedef struct LNode
{
    ElemType data;
    struct LNode* next;//LinkList L;    ==  LNode* L;
}LNode,*LinkList;
/*等价于
struct LNode{
    ElemType data;
    struct LNode* next;
};
typedef struct LNode LNode;
typedef struct LNode* LinkList;
*/
bool InitList(LinkList &L)
{//初始化
    /*不带头的单链表
    return (L=NULL);
    */
    //带头的单链表
    L=new LNode;//创建头节点
    //L=(LNode*)malloc(sizeof(LNode));
    if(L==NULL)
    {//内存不足，分配失败
        return false;
    }
    L->next=NULL;
    return true;
}