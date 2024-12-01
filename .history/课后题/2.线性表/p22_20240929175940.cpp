#include <iostream>
using namespace std;
#include "init-linear.h"
//01
bool delmin(SqList &L,ElemType &min){
    if (L.length!=0)
    {   
        min=L.data[0];
        int j=0;
        for (int i = 1; i < L.length; i++)
        {
            if (L.data[i]<min)
            {
                min=L.data[i];
                j=i;
            }
        }
        L.data[j]=L.data[L.length-1];
        L.length--;
        return true;
    }
    return false;
}