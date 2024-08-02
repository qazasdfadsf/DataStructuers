#include<iostream>
using namespace std;
struct ElemType
{
    int value;
    // 重载 == 运算符
    bool operator==(const ElemType& other) const {
        return value == other.value;
    }
     bool operator!=(const ElemType& other) const {
        return value != other.value;
    }
};
typedef struct {
    int id;                    // 顶点的ID
} VertexType;