/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 *
 * https://leetcode.com/problems/surface-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (56.96%)
 * Likes:    214
 * Dislikes: 278
 * Total Accepted:    16.2K
 * Total Submissions: 27.9K
 * Testcase Example:  '[[2]]'
 *
 * On a N * N grid, we place some 1 * 1 * 1 cubes.
 *
 * Each value v = grid[i][j] represents a tower of v cubes placed on top of
 * grid cell (i, j).
 *
 * Return the total surface area of the resulting shapes.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [[2]]
 * Output: 10
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,2],[3,4]]
 * Output: 34
 *
 *
 *
 * Example 3:
 *
 *
 * Input: [[1,0],[0,2]]
 * Output: 16
 *
 *
 *
 * Example 4:
 *
 *
 * Input: [[1,1,1],[1,0,1],[1,1,1]]
 * Output: 32
 *
 *
 *
 * Example 5:
 *
 *
 * Input: [[2,2,2],[2,1,2],[2,2,2]]
 * Output: 46
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= N <= 50
 * 0 <= grid[i][j] <= 50
 *
 *
 *
 *
 *
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int surfaceArea(vector<vector<int>> &grid) {
        int n = grid.size();
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    // 上下
                    area += 2;
                    // 前后
                    if (i == 0)
                        area += grid[i][j];
                    else
                        area += (grid[i - 1][j] > grid[i][j] ? 0 : (grid[i][j] - grid[i - 1][j]));
                    if (i == n - 1)
                        area += grid[i][j];
                    else
                        area += (grid[i + 1][j] > grid[i][j] ? 0 : (grid[i][j] - grid[i + 1][j]));
                    // 左右
                    if (j == 0)
                        area += grid[i][j];
                    else
                        area += (grid[i][j - 1] > grid[i][j] ? 0 : (grid[i][j] - grid[i][j - 1]));
                    if (j == n - 1)
                        area += grid[i][j];
                    else
                        area += (grid[i][j + 1] > grid[i][j] ? 0 : (grid[i][j] - grid[i][j + 1]));
                }
            }
        }
        return area;
    }
};
// @lc code=end
