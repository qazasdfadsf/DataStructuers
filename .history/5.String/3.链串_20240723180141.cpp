#include "init.h"
typedef struct StringNode
{
    char ch[4];//数字可改;填充空位
    struct StringNode* next;
}StringNode,*String;
