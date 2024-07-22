typedef struct StringNode
{
    char ch[4];
    struct StringNode* next;
}StringNode,*String;
