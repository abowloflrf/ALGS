#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class DirectedGraphNode {
  public:
    int tag;
    int time;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int t, int x) : tag(t), time(x) {};
};

class Solution {
  public:
    void findFromStart() {
        for (auto node:systems) {
            if (degrees[node] == 0) {
                vector<DirectedGraphNode *> path;
                int currentSum = 0;
                findPath(node, path, currentSum);
            }
        }
    }
    void findPath(DirectedGraphNode *currentNode, vector<DirectedGraphNode *> currentPath, int currentTime) {
        //访问到这个节点，则将当前节点加入到路径中
        currentPath.push_back(currentNode);
        currentTime += currentNode->time;
        //到尽头
        if (currentNode->neighbors.size() == 0) {
            pathCount++;
            if (currentTime > maxTime)
                maxTime = currentTime;
            return;
        }
        //继续向下寻找
        for (auto node:currentNode->neighbors) {
            findPath(node, currentPath, currentTime);
        }
    }
    Solution(vector<DirectedGraphNode *> s) : systems(s) {
        maxTime = 0;
        pathCount = 0;
        //遍历图保存入度
        for (auto node: systems) {
            //未找到则加入新的节点并初始化入度为0
            if (degrees.find(node) == degrees.end()) {
                degrees[node] = 0;
            }

            for (auto n:node->neighbors) {
                degrees[n]++;
            }
        }
    }
    int getTime() {
        return maxTime;
    }
    int getCount() {
        return pathCount;
    }
  private:

    vector<DirectedGraphNode *> systems;
    unordered_map<DirectedGraphNode *, int> degrees;
    int maxTime;
    int pathCount;
};

int main() {
    vector<DirectedGraphNode *> systems;
    systems.push_back(new DirectedGraphNode(1, 3));
    systems.push_back(new DirectedGraphNode(2, 2));
    systems.push_back(new DirectedGraphNode(3, 10));
    systems.push_back(new DirectedGraphNode(4, 5));
    systems.push_back(new DirectedGraphNode(5, 7));
    //构建依赖关系
    systems[0]->neighbors.push_back(systems[1]);
    systems[0]->neighbors.push_back(systems[2]);
    systems[1]->neighbors.push_back(systems[4]);
    systems[3]->neighbors.push_back(systems[4]);
    //计算依赖路径
    Solution s(systems);
    s.findFromStart();

    cout << s.getCount() << endl;
    cout << s.getTime() << endl;
    return 0;
}