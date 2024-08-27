#include "init.h"
void swap(int &a,int &b)
{//交换
    int temp=a;
    a=b;
    b=temp;
}
void BubbleSort(int A[],int n)
{//冒泡排序 空间O(1)    时间O(n^2)  稳定
    for (int i = 0; i < n-1; i++)
    {
        bool flag=false;
        for (int j = n-1; j<i; j--)
        {
            if (A[j-1]>A[j])
            {
                swap(A[j-1],A[j]);
                flag=true;
            }
        }
        if (flag==false)
            return;
    }
}
//适用于链表