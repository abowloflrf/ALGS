#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {

        // 构造 graph
        graph = vector<unordered_set<int>>(patience.size(), unordered_set<int>{});
        for (auto e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        // 默认 -1
        minPathMap = vector<int>(patience.size(), INT32_MAX);
        minPathMap[0] = 0;

        // 计算所有点到 0 的最短路径
        queue<int> q;
        q.push(0);
        vector<bool> complete(patience.size(), false);
        while (!q.empty()) {
            int target = q.front();
            q.pop();
            for (auto i : graph[target]) {
                minPathMap[i] = min(minPathMap[i], minPathMap[target] + 1);
                if (complete[i] == false) {
                    complete[i] = true;
                    q.push(i);
                }
            }
        }

        // 开始对除 0 的每一个点计算最长时间
        int maxTime = INT32_MIN;
        for (int i = 1; i < patience.size(); i++) {
            int d = minPathMap[i] * 2;
            int interval = patience[i];
            int k = d / interval;
            if (d % interval == 0)
                k--;
            maxTime = max(maxTime, k * interval + d);
        }
        return maxTime + 1;
    }

  private:
    // 找到  n 到  0  的最短路径
    vector<int> minPathMap;
    vector<unordered_set<int>> graph;
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> a = {{0, 1}, {0, 2}, {1, 2}};
    vector<int> b = {0, 10, 10};
    int ans = s.networkBecomesIdle(a, b);
    return 0;
}
