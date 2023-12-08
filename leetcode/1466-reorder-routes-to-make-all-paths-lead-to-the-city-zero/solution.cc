/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 *
 * https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
 *
 * algorithms
 * Medium (57.53%)
 * Likes:    211
 * Dislikes: 0
 * Total Accepted:    31.4K
 * Total Submissions: 52.1K
 * Testcase Example:  '6\n[[0,1],[1,3],[2,3],[4,0],[4,5]]'
 *
 * There are n cities numbered from 0 to n - 1 and n - 1 roads such that there
 * is only one way to travel between two different cities (this network form a
 * tree). Last year, The ministry of transport decided to orient the roads in
 * one direction because they are too narrow.
 *
 * Roads are represented by connections where connections[i] = [ai, bi]
 * represents a road from city ai to city bi.
 *
 * This year, there will be a big event in the capital (city 0), and many
 * people want to travel to this city.
 *
 * Your task consists of reorienting some roads such that each city can visit
 * the city 0. Return the minimum number of edges changed.
 *
 * It's guaranteed that each city can reach city 0 after reorder.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
 * Output: 3
 * Explanation: Change the direction of edges show in red such that each node
 * can reach the node 0 (capital).
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
 * Output: 2
 * Explanation: Change the direction of edges show in red such that each node
 * can reach the node 0 (capital).
 *
 *
 * Example 3:
 *
 *
 * Input: n = 3, connections = [[1,0],[2,0]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 5 * 10^4
 * connections.length == n - 1
 * connections[i].length == 2
 * 0 <= ai, bi <= n - 1
 * ai != bi
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int minReorder(int n, vector<vector<int>> &connections) {
        // 1. 构造图（可以看成树）
        vector<vector<pair<int, int>>> g(n);
        for (auto c : connections) {
            // pair.first 为目的地
            // pair.second 为方向标记
            g[c[0]].push_back(make_pair(c[1], 1)); // 原方向
            g[c[1]].push_back(make_pair(c[0], 0)); // 不存在
        }
        // 2. 从根节点（0）出发，dfs
        return dfs(0, -1, g);
    }
    int dfs(int n, int parent, vector<vector<pair<int, int>>> &g) {
        int ans = 0;

        for (auto line : g[n]) {
            if (line.first != parent) {
                // 原方向不对，需要调整此道路
                ans += line.second;
                ans += dfs(line.first, n, g);
            }
        }
        return ans;
    }
};
// @lc code=end
