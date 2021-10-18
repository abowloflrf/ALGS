/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (78.95%)
 * Likes:    496
 * Dislikes: 0
 * Total Accepted:    130.5K
 * Total Submissions: 165.3K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate an n x n matrix filled with elements
 * from 1 to n^2 in spiral order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: [[1,2,3],[8,9,4],[7,6,5]]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, -1));
        // 定义上下左右边界
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int x = 0, y = 0;
        int c = 1;
        while (c <= n * n) {
            // 向右
            for (int i = left; i <= right; i++) {
                ans[up][i] = c++;
            }
            up++;
            // 向下
            for (int i = up; i <= down; i++) {
                ans[i][right] = c++;
            }
            right--;
            // 向左
            for (int i = right; i >= left; i--) {
                ans[down][i] = c++;
            }
            down--;
            // 向上
            for (int i = down; i >= up; i--) {
                ans[i][left] = c++;
            }
            left++;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    Solution s;
    s.generateMatrix(4);
    return 0;
}
