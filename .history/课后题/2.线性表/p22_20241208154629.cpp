#include <iostream>
using namespace std;
#include "init-linear.h"
//2.2.4 01从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
// bool Del_Min(SqList &L,int &e){//bool Del_Min(SqList &L,ElemType &value)
//     if(L.length==0){
//         return false;
//     }else{
//         int min=L.data[0];//value=L.data[0]
//         int num=0;//int pos=0;
//         for(int i=0;i<L.length;i++){
//             if(L.data[i]<min){
//                 min=L.data[i];
//                 num=i;
//             }
//         }
//         L.data[num]=L.data[L.length-1];
//         L.length--;
//         e=min;
//         return true;
//     }
// }
// //2.2.4 02设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为 O（1）
// void Reverse(SqList &L){
//     int r;
//     for(int i=0;i<L.length/2;i++){
//         int j=L.length-1-i;
//         r=L.data[i];
//         L.data[i]=L.data[j];
//         L.data[j]=r;
        
//     }
// }
// //2.2.4 03对长度为n的顺序表L，编写一个时间复杂度为O（n）、空间复杂度为O（1）的算法，该算法刪除顺序表中所有值为x的数据元素。
// bool delete_x(SqList &L, int x) {
//     int k = 0; // 用于记录非x元素的位置
//     for (int i = 0; i < L.length; i++) {
//         if (L.data[i] != x) {
//             L.data[k] = L.data[i]; // 将非x元素移动到新的位置
//             k++; // 更新非x元素位置指针
//         }
//     }
//     L.length = k; // 更新顺序表的长度
//     return true; // 返回删除成功
// }
// //2.2.4 04.从顺序表中删除其值在给定值s和t之间（包含s和t，要求s<t）的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行。
// bool del_s_t(SqList &L, int s, int t) {
//     if (s < 0 || t >= L.length || s >= t) {
//         return false; // s 或 t 不合理
//     }

//     int k = 0; // k指向被删除元素的位置
//     for (int i = 0; i < L.length; i++) {
//         if (L.data[i] >= s && L.data[i] <= t) {
//             k++;
//         } else {
//             L.data[i - k] = L.data[i]; // 将不在删除范围内的元素向前移动
//         }
//     }

//     L.length -= k; // 更新顺序表的长度
//     return true;
// }
// //2.2.4 05.从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
// bool del_repeat(SqList &L){
//     if(L.length==0){
//         return false;
//     }else{
//         int i,j;
//         for( i=0,j=1;j<L.length;j++){
//             if(L.data[i]!=L.data[j]){
//                 L.data[++i]=L.data[j];
//             }
//         }
//         L.length=i+1;
//         return true;
//     }
// }
// int main(){
//     SqList L;
//     L.length=11;
//     for(int i=0;i<11;i++){
//         L.data[i]=i;
//     }
//     cout << "有序顺序表：";

//     for (int i = 0; i < L.length; i++) {
//         cout << L.data[i] <<" ";
//     }
//     cout<<endl;
//     cout<<L.length<<endl;

//     // 删除重复元素
//     del_repeat(L);

//     // 输出删除重复元素后的有序顺序表
//     cout << "删除重复元素后的有序顺序表：";
//     for (int i = 0; i < L.length; i++) {
//         cout << L.data[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }