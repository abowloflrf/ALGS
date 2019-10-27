/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (49.74%)
 * Likes:    2015
 * Dislikes: 147
 * Total Accepted:    348.1K
 * Total Submissions: 699.2K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 *
 *
 * Example 2:
 *
 *
 * Input: m = 7, n = 3
 * Output: 28
 *
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    int uniquePaths(int m, int n) {
        dpM = vector<vector<int>>(m, vector<int>(n, -1));
        if (m == 1 || n == 1)
            return 1;
        for (auto &mm : dpM) {
            mm[0] = 1;
        }
        for (auto &nn : dpM[0]) {
            nn = 1;
        }
        return dp(m, n);
    }

  private:
    vector<vector<int>> dpM;
    int dp(int m, int n) {
        int cur = dpM[m - 1][n - 1];
        if (cur > -1)
            return cur;
        int res = dp(m - 1, n) + dp(m, n - 1);
        dpM[m - 1][n - 1] = res;
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    int res = s.uniquePaths(19, 13);
    return 0;
}
