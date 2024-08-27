//  AVL树
#include "init.h"
typedef struct AVLNode
{
    int key;
    int balance;//平衡因子
    struct AVLNode *lchild,*rchild;
}AVLNode,*AVLTree;

