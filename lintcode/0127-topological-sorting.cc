//拓扑排序
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

//表示图节点的数据结构
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode*> neighbors;
    DirectedGraphNode(int x) : label(x){};
};

class Solution {
   public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        vector<DirectedGraphNode*> result;  //记录结果，记录图所有节点的有序数组
        unordered_map<DirectedGraphNode*, int> degrees;  //记录所有节点的度

        //遍历图来构造degrees统计所有节点的度数，保存在map中
        for (auto node : graph) {
            if (degrees.find(node) == degrees.end()) {
                degrees[node] = 0;
            }
            for (DirectedGraphNode* neighbor : node->neighbors) {
                degrees[neighbor]++;
            }
        }

        //遍历保存了度数的map，找出度数为0的起始节点保存在队列Q中
        queue<DirectedGraphNode*> Q;
        for (auto it = degrees.begin(); it != degrees.end(); it++) {
            if (it->second == 0) {
                Q.push(it->first);
            }
        }

        //从Q中循环取出节点加入到results
        while (!Q.empty()) {
            DirectedGraphNode* node = Q.front();  //取值
            result.push_back(node);               //加入
            Q.pop();                              //删除
            //在取出的起始节点的邻居中遍历得到度为0的点，再次加入队列
            for (DirectedGraphNode* neighbor : node->neighbors) {
                if (--degrees[neighbor] == 0) {
                    Q.push(neighbor);
                }
            }
        }

        return result;
    }
};