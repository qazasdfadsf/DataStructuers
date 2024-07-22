#include<iostream>
using namespace std;
#define MaxSize 100
struct TreeNode
{
    int value;//ElemType value;
    bool isEmpty;
};
int main()
{
    TreeNode t[MaxSize];
    return 0;
}
void visit(TreeNode *T){
    printf("%d",T->data);
}
void PreOrder(TreeNode*R){
    if(R!=NULL){
        visit(R);
    }
}