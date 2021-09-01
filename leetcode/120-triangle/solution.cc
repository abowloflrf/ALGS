/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (67.91%)
 * Likes:    834
 * Dislikes: 0
 * Total Accepted:    170.8K
 * Total Submissions: 251.5K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle array, return the minimum path sum from top to bottom.
 *
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 *
 *
 * Example 1:
 *
 *
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
 * above).
 *
 *
 * Example 2:
 *
 *
 * Input: triangle = [[-10]]
 * Output: -10
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^4
 *
 *
 *
 * Follow up: Could you do this using only O(n) extra space, where n is the
 * total number of rows in the triangle?
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    // dp 二维数组保存历史结果
    int minimumTotal(vector<vector<int>> &triangle) {
        int height = triangle.size();
        int weight = triangle.back().size();
        // dp[i][j] 为从顶部到 [i][j] 的最短路径
        int dp[height][weight];
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < height; i++) {
            // j==0 时 dp[i][0] = dp[i-1][0] + c[i][0]
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; j++) {
                // 中间情况时，dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + c[i][j]
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
            // j==i 时 dp[i][i] = dp[i-1][i-1] + c[i][i]
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }

        int minPath = __INT32_MAX__;
        for (int i = 0; i < weight; i++) {
            if (dp[height - 1][i] < minPath)
                minPath = dp[height - 1][i];
        }
        return minPath;
    }
};
// @lc code=end

// 直接递归 DFS，会超时
class Solution1 {
  public:
    int dfs(vector<vector<int>> &triangle, int i, int j) {
        // 超过底层，不用走了
        if (triangle.size() == i) {
            return 0;
        }
        return min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)) + triangle[i][j];
    }
    int minimumTotal(vector<vector<int>> &triangle) {
        // 从 (0,0,) 出发的最小值
        return dfs(triangle, 0, 0);
    }
};

// 更简单的 dp
class Solution2 {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int height = triangle.size();
        int weight = triangle.back().size();
        // dp[i][j] 为从 [i][j] 到底边的最短路径
        int dp[height][weight];
        // 从底部开始判断
        for (int i = height - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // 最底边时，直接取当前值即可
                if (i == height - 1) {
                    dp[i][j] = triangle[height - 1][j];
                } else {
                    // 取自下一层
                    dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
                }
            }
        }
        return dp[0][0];
    }
};