#include "init.h"
// 双亲表示法
#define MAX_TREE_SIZE 100
struct ElemType
{
    int value;
};
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
