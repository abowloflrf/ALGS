/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.cn/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (51.21%)
 * Likes:    783
 * Dislikes: 0
 * Total Accepted:    135.9K
 * Total Submissions: 265.5K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * You are given an m x n grid where each cell can have one of three
 * values:
 *
 *
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 *
 *
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
 * orange becomes rotten.
 *
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange. If this is impossible, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 * rotten, because rotting only happens 4-directionally.
 *
 *
 * Example 3:
 *
 *
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 *
 *
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        int count = 0;
        int rottedCount = 0;
        queue<pair<int, int>> q;
        int minute = -1;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[0].size(); y++) {
                if (grid[x][y] != 0) {
                    count++;
                    if (grid[x][y] == 2) {
                        q.push({x, y});
                    }
                }
            }
        }
        // 开始 bfs
        rottedCount = q.size();
        while (!q.empty()) {
            int size = q.size();
            minute++;
            for (int i = 0; i < size; i++) {
                // 对每个腐烂的橘子周围开始弥漫
                auto node = q.front();
                int x = node.first, y = node.second;
                q.pop();
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    rottedCount++;
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                }
                if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
                    rottedCount++;
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    rottedCount++;
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                }
                if (y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
                    rottedCount++;
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                }
            }
        }
        if (count == 0) {
            return 0;
        }
        if (rottedCount == count) {
            return minute;
        }
        return -1;
    }
};
// @lc code=end
