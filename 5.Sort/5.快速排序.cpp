#include "init.h"

// Partition函数用于将数组A进行划分，并返回枢轴元素的最终位置
int Partition(int A[], int low, int high)
{
    int pivot = A[low]; // 选择第一个元素作为枢轴元素
    while (low < high)
    {
        // 从右向左扫描，找到第一个小于枢轴的元素
        while (low < high && A[high] >= pivot)
            --high;
        A[low] = A[high]; // 将该元素移到左边

        // 从左向右扫描，找到第一个大于枢轴的元素
        while (low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low]; // 将该元素移到右边
    }
    A[low] = pivot; // 将枢轴元素放到最终位置
    return low;     // 返回枢轴元素的位置
}

// QuickSort函数用于对数组A进行快速排序
void QuickSort(int A[], int low, int high)
{
    if (low < high) // 递归终止条件：low不小于high
    {
        // 对数组进行划分，并获取枢轴元素的位置
        int pivotpos = Partition(A, low, high);
        
        // 递归排序枢轴左侧部分
        QuickSort(A, low, pivotpos - 1);
        
        // 递归排序枢轴右侧部分
        QuickSort(A, pivotpos + 1, high);
    }
}
