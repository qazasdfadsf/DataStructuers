#include "init.h"
#include <vector>
using namespace std;

// 定义边结点结构体
struct EdgeNode {
    int adjVex; // 该边所指向的顶点
    EdgeNode *next; // 指向下一条边的指针
};

// 定义顶点结点结构体
struct VertexNode {
    int data; // 顶点信息
    EdgeNode *firstEdge; // 指向第一条依附于该顶点的边
};

// 定义图结构体
class Graph {
public:
    vector<VertexNode> adjList; // 顶点数组
    int vexNum, edgeNum; // 图的顶点数和边数

    // 构造函数
    Graph(int vNum) : vexNum(vNum), edgeNum(0) {
        adjList.resize(vNum);
        for (int i = 0; i < vNum; ++i) {
            adjList[i].data = i; // 顶点数据可以根据需要修改
            adjList[i].firstEdge = nullptr;
        }
    }

    // 插入边
    void insertEdge(int start, int end) {
        EdgeNode *newNode = new EdgeNode;
        newNode->adjVex = end;
        newNode->next = adjList[start].firstEdge;
        adjList[start].firstEdge = newNode;
        ++edgeNum;
    }

    // 删除边
    void deleteEdge(int start, int end) {
        EdgeNode *prev = nullptr;
        EdgeNode *curr = adjList[start].firstEdge;
        while (curr != nullptr && curr->adjVex != end) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != nullptr) {
            if (prev == nullptr) {
                adjList[start].firstEdge = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            --edgeNum;
        }
    }

    // 查找边
    bool findEdge(int start, int end) {
        EdgeNode *curr = adjList[start].firstEdge;
        while (curr != nullptr) {
            if (curr->adjVex == end) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    // 遍历图（深度优先搜索）
    void DFS(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        EdgeNode *curr = adjList[v].firstEdge;
        while (curr != nullptr) {
            if (!visited[curr->adjVex]) {
                DFS(curr->adjVex, visited);
            }
            curr = curr->next;
        }
    }

    // 遍历图（广度优先搜索）
    void BFS(int v) {
        vector<bool> visited(vexNum, false);
        vector<int> queue;
        visited[v] = true;
        queue.push_back(v);
        int front = 0;
        while (front < queue.size()) {
            int currV = queue[front++];
            cout << currV << " ";
            EdgeNode *curr = adjList[currV].firstEdge;
            while (curr != nullptr) {
                if (!visited[curr->adjVex]) {
                    visited[curr->adjVex] = true;
                    queue.push_back(curr->adjVex);
                }
                curr = curr->next;
            }
        }
    }
};

