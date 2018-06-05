#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

class Solution {
   public:
    /**
     * @param n: a integer
     * @param flights: a 2D array
     * @param src: a integer
     * @param dst: a integer
     * @param K: a integer
     * @return: return a integer
     */
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int K) {
        //将所有航班的情况构造为一个图
        for (auto f : flights) graph[f[0]].push_back({f[1], f[2]});

        //记录访问过的地点
        vector<int> visited(n, 0);
        visited[src] = 1;

        //初始化结果为INT_MAX
        int res = INT_MAX;

        dfs(src, dst, K + 1, 0, visited, res);
        return res == INT_MAX ? -1 : res;
    }

   private:
    unordered_map<int, vector<pair<int, int>>> graph;
    void dfs(int current, int dst, int k, int cost, vector<int> &visited,
             int &res) {
        // current==dst 表明已经到达目的地
        if (current == dst) {
            res = cost;
            return;
        }
        // k==0 表明可中转数已经耗尽，直接返回当前最优结果
        if (k == 0) return;

        // graph[current]保存的为当前位置出发的所有航班信息，first为目的地，second为票价
        for (auto &p : graph[current]) {
            if (visited[p.first])
                continue;  //这个目的在之前已经中转过，不再计算
            if (cost + p.second > res)
                continue;  //若加上这个票价后价格大于目前的结果，不再计算

            //开始计算中转这个目的的票价，并将这个目的标记为已经中转过
            visited[p.first] = 1;
            //递归计算，其中current改为此时中转的目的地，k为总共可中转次数减一
            dfs(p.first, dst, k - 1, cost + p.second, visited, res);
            //将此地标为未访问过，并进行第二个地点的中转
            visited[p.first] = 0;
        }
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int price = s.findCheapestPrice(3, flights, 0, 2, 0);
    return 0;
}