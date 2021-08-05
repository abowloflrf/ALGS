/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (47.69%)
 * Likes:    840
 * Dislikes: 0
 * Total Accepted:    173.2K
 * Total Submissions: 363.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return {};
        }
        vector<int> res;
        int width = matrix[0].size(), height = matrix.size();
        int up = 0, down = height - 1, left = 0, right = width - 1;
        while (true) {
            // 左向右，up 不变
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[up][i]);
            }
            if (++up > down)
                break;
            // 上到下，right 不变
            for (int i = up; i <= down; i++) {
                res.push_back(matrix[i][right]);
            }
            if (--right < left) {
                break;
            }
            // 右到左，down 不变
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[down][i]);
            }
            if (--down < up) {
                break;
            }
            // 下到上，left 不变
            for (int i = down; i >= up; i--) {
                res.push_back(matrix[i][left]);
            }
            if (++left > right)
                break;
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> input = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    auto a = s.spiralOrder(input);
    return 0;
}
