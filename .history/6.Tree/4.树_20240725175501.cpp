#include "init.h"
// 双亲表示法
#define MAX_TREE_SIZE 100
typedef struct 
{
    ElemType data;
    int parent;
}PTNode;
typedef struct 
{
    PTNode nodes[MAX_TREE_SIZE];
    int n;//节点总数
}PTree;
//找父节点方便，找孩子节点需要遍历数组

// 孩子表示法
struct CTNode
{
    int child;
    struct CTNode *next;
};
typedef struct 
{
    ElemType data;
    struct CTNode *firstChild;
}CTBox;
typedef struct 
{
    CTBox nodes[MAX_TREE_SIZE];
    int n,r;//节点总数和根的位置
}CTree;
//找孩子方便，找双亲结点不方便，需要遍历整个链表
//服务流程树

