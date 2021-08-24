/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (38.95%)
 * Likes:    614
 * Dislikes: 0
 * Total Accepted:    171.2K
 * Total Submissions: 439.6K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 *
 * An obstacle and space is marked as 1 and 0 respectively in the grid.
 *
 *
 * Example 1:
 *
 *
 * Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation: There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 *
 *
 * Example 2:
 *
 *
 * Input: obstacleGrid = [[0,1],[0,0]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] is 0 or 1.
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                // 若出现一个则后面都是 0
                for (int j = i; j < m; j++) {
                    dp[j][0] = 0;
                }
                break;
            } else
                dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) {
                for (int j = i; j < n; j++) {
                    dp[0][j] = 0;
                }
                break;
            } else
                dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
