/**
 * 拓扑排序 Topological sorting。
 * https://oi-wiki.org/graph/topo/
 *
 * 要解决的问题是给一个图的所有节点排序
 * 当且仅当图中没有环时（有向无环图），才能有拓扑排序，因此拓扑排序算法也可以用来判断给定的图
 * 是否有环
 *
 * 一个有向无环图的定点组成的序列，当且仅当满足以下条件时，成为该图的一个拓扑排序
 * 1. 序列中包含每个定点，且只出现一次
 * 2. 若A在序列中排在B的前面，则图中不存在从B到A的路径
 *
 * 有两种算法
 * 1. Kahn 卡恩算法
 * 2. DFS 深度优先遍历算法
 **/

#include "./utils/graph.h"
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Kahn
vector<DirectedGraphNode *> topSort_kahn(vector<DirectedGraphNode *> &graph) {
    vector<DirectedGraphNode *> L;                   //保存结果
    queue<DirectedGraphNode *> S;                    //保存入度为0的节点
    unordered_map<DirectedGraphNode *, int> degrees; //保存所有节点的入度

    // 计算所有节点入度
    for (auto i : graph) {
        if (degrees.find(i) == degrees.end())
            degrees[i] = 0;
        for (auto j : i->neighbors) {
            if (degrees.find(j) == degrees.end())
                degrees[j] = 1;
            else
                degrees[j]++;
        }
    }
    // 将入度为0的节点加入到队列
    for (auto d : degrees) {
        if (d.second == 0)
            S.push(d.first);
    }

    while (!S.empty()) {
        DirectedGraphNode *node = S.front();
        S.pop();
        L.push_back(node);

        for (auto n : node->neighbors) {
            degrees[n]--;
            if (degrees[n] == 0) {
                S.push(n);
            }
        }
    }
    return L;
}

// DFS
vector<DirectedGraphNode *> topSort_dfs(vector<DirectedGraphNode *> &graph) {}

int main(int argc, char const *argv[]) {
    DirectedGraphNode *node0 = new DirectedGraphNode(0);
    DirectedGraphNode *node1 = new DirectedGraphNode(1);
    DirectedGraphNode *node2 = new DirectedGraphNode(2);
    DirectedGraphNode *node3 = new DirectedGraphNode(3);
    DirectedGraphNode *node4 = new DirectedGraphNode(4);
    DirectedGraphNode *node5 = new DirectedGraphNode(5);
    node0->neighbors = {node1, node2, node3};
    node1->neighbors = {node4};
    node2->neighbors = {node4, node5};
    node3->neighbors = {node4, node5};
    vector<DirectedGraphNode *> g = {node0, node1, node2, node3, node4, node5};
    auto r = topSort_kahn(g);
    return 0;
}
