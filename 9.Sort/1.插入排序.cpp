#include "init.h"
void InsertSort(int A[],int n)
{//直接插入排序 空间O(1)    时间O(n^2)
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        if (A[i]<A[i-1])
        {
            temp=A[i];
            for(j=i-1;j>=0 && A[j]>temp;--j)
                A[j+1]=A[j];
            A[j+1]=temp;
        }
        
    }
}
