#ifndef MY_HEADER_H // 防止重复包含
#define MY_HEADER_H

#include <iostream> // 包含输入输出流头文件
using namespace std;

// 定义元素类型结构体
struct ElemType {
    int value; // 元素的值

    // 重载 == 运算符，用于比较两个 ElemType 是否相等
    