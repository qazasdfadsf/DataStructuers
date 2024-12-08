#include "init.h"
#define MaxSize 10
typedef struct 
{
    ElemType data[MaxSize];
    int length;
}SqList;//Sequence List
void InitList(SqList &L)
{//初始化
    for(int i=0;i<MaxSize;i++)
    {//将每一个数据元素设置为默认初始值
        L.data[i].value=0;
    }
    L.length=0;
}
bool ListInsert(SqList &L,int i,ElemType e)
{//插入操作 O(n)
    if(i<1||i>L.length)
    {//检验i是否合法
        return false;
    }
    if(L.length==MaxSize)
    {//检查列表是否已满
        return false;
    }
    //插入元素
    for(int j=L.length;j>=i;j--)
    {//将第i个元素及之后的元素后移
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
    
}
bool ListDelete(SqList &L,int i,ElemType &e)
{//删除操作 O(n)
    if(i<1||i>L.length)
    {//检验i是否合法
        return false;
    }
    //删除元素
    e=L.data[i-1];
    for(int j=i;j<L.length;j++)
    {//将第i个位置后的元素前移一位
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}
ElemType GetElem(SqList L, int i)
{//按位查找 O(1)
    return L.data[i - 1];
}
int LocateElem(SqList &L,ElemType e)
{//按值查找  O(n)
    int i;
    for(i=0;i<L.length;i++)
    {
        if(L.data[i]==e)
        {
            return i+1;
        }
    }
    return 0;
}

int main(){
    SqList L;
    return 0;
}
/*真题=====================================================================================================================================*/
//2010年
void Reverse(int R[],int from,int to)
{
    int i,temp;
    for(i=0;i<(to-from+1)/2;i++)
    {
        temp=R[from+i];
        R[from+i]=R[to-i];
        R[to-i]=temp;
    }
}
void Converse(int R[],int n,int p)
{
    Reverse(R,0,p-1);
    Reverse(R,0,p-1);
}
