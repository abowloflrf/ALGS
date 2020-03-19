/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (43.33%)
 * Likes:    4317
 * Dislikes: 158
 * Total Accepted:    571.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 *
 * Example 1:
 *
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        int height = grid.size();
        if (height == 0)
            return 0;
        int width = grid.front().size();
        int cnt = 0;
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '1')
                    cnt++;
                clearIsland(grid, j, i);
            }
        return cnt;
    }

  private:
    void clearIsland(vector<vector<char>> &grid, int x, int y) {
        if (x < 0 || x == grid.front().size() || y < 0 || y == grid.size())
            return;
        if (grid[y][x] == '0')
            return;
        grid[y][x] = '0';
        clearIsland(grid, x + 1, y);
        clearIsland(grid, x, y + 1);
        clearIsland(grid, x - 1, y);
        clearIsland(grid, x, y - 1);
        return;
    }
};
// @lc code=end
