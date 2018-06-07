#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> getOrder(vector<vector<int>> pLists) {
    unordered_map<int, unordered_set<int>> graph;
    unordered_map<int, int> degrees;

    //构建图与所有节点的入度
    for (auto list : pLists) {
        for (int i = 0; i < list.size() - 1; i++) {
            int from = list[i];
            int to = list[i + 1];
            //若from节点不存在则在graph与degree中初始化该节点
            if (!graph.count(from)) {
                graph[from] = {};
                degrees[from] = 0;
            }
            //若to节点不存在则在graph与degree中初始化该节点
            if (!graph.count(to)) {
                graph[to] = {};
                degrees[to] = 0;
            }
            //若在图中from没有被标记为指向to则在from指向的set中插入to
            if (!graph[from].count(to)) {
                graph[from].insert(to);
            }
            // to的入度+1
            degrees[to]++;
        }
    }

    //构建队列，将记录入度的节点中，入度为0的所有节点入队
    queue<int> mQueue;
    for (auto d : degrees) {
        if (d.second == 0) mQueue.push(d.first);
    }

    //根据队列依次出队的同时，更新入度，在循环中将入度为0的节点依次加入队列
    vector<int> result;
    while (!mQueue.empty()) {
        int p = mQueue.front();
        mQueue.pop();
        result.push_back(p);  //从入度为0的队列中取出一个加入到结果
        for (auto node : graph[p]) {
            //从图中遍历取出的节点所指向的节点set，所有入度都递减1
            //若递减1后入度变为0，则将该节点加入到队列中
            if (--degrees[node] == 0) mQueue.push(node);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> pLists = {{3, 5, 7, 9}, {2, 3, 8}, {5, 8}};
    vector<int> result = getOrder(pLists);
    return 0;
}