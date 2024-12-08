#ifndef MY_HEADER_H // 防止重复包含
#define MY_HEADER_H
using namespace std;
#include <iostream> // 包含输入输出流头文件


// 定义元素类型结构体
struct ElemType {
    int value; // 元素的值

    // 重载 == 运算符，用于比较两个 ElemType 是否相等
    bool operator==(const ElemType& other) const {
        return value == other.value;
    }

    // 重载 > 运算符，用于比较两个 ElemType 的大小
    bool operator>(const ElemType& other) const {
        return value > other.value;
    }

    // 重载 < 运算符，用于比较两个 ElemType 的大小
    bool operator<(const ElemType& other) const {
        return value < other.value;
    }

    // 重载 != 运算符，用于比较两个 ElemType 是否不相等
    bool operator!=(const ElemType& other) const {
        return value != other.value;
    }
    
};
std::ostream& operator<<(std::ostream& os, const ElemType& elem) {
    os << elem.value;
    return os;
}

// 顶点类型结构体，用于图的表示
struct VertexType {
    int id; // 顶点的ID

    // 重载 == 运算符，用于比较两个 VertexType 是否相等
    bool operator==(const VertexType& other) const {
        return id == other.id;
    }

    // 重载 != 运算符，用于比较两个 VertexType 是否不相等
    bool operator!=(const VertexType& other) const {
        return id != other.id;
    }
};

// 模拟访问边的函数
bool visit(int edge) {
    std::cout << "Visiting edge: " << edge << std::endl;
    return true; // 返回 true 表示访问成功
}

#endif // MY_HEADER_H
//Linear
// 定义顺序栈的结构体
struct SqStack {
    char *data;  // 数据数组
    int top;     // 栈顶指针
    int maxSize; // 栈的最大容量
};

// 函数声明
void InitStack(SqStack &S);
bool StackEmpty(SqStack S);
bool Push(SqStack &S, char x);
bool Pop(SqStack &S, char &x);
