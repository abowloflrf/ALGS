/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode-cn.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (61.88%)
 * Likes:    642
 * Dislikes: 0
 * Total Accepted:    165.1K
 * Total Submissions: 266.8K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 *
 * Return the total number of provinces.
 *
 *
 * Example 1:
 *
 *
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 *
 *
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // 对于这 n 个节点，每个节点进行一遍 dfs ，并在 dfs 过程中标记所有与之相连的节点为 visited
            if (!visited[i]) {
                dfsVisit(isConnected, i);
                ans++;
            }
        }

        return ans;
    }

  private:
    // 记录访问过的节点
    bool visited[200];

    void dfsVisit(vector<vector<int>> &isConnected, int i) {
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] && !visited[j]) {
                visited[j] = true;
                dfsVisit(isConnected, j);
            }
        }
    }
};
// @lc code=end
