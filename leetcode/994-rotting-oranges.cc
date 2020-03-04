/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Easy (47.11%)
 * Likes:    926
 * Dislikes: 131
 * Total Accepted:    54.8K
 * Total Submissions: 116.2K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * In a given grid, each cell can have one of three values:
 *
 *
 * the value 0 representing an empty cell;
 * the value 1 representing a fresh orange;
 * the value 2 representing a rotten orange.
 *
 *
 * Every minute, any fresh orange that is adjacent (4-directionally) to a
 * rotten orange becomes rotten.
 *
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange.  If this is impossible, return -1 instead.
 *
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation:  The orange in the bottom left corner (row 2, column 0) is
 * never rotten, because rotting only happens 4-directionally.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: [[0,2]]
 * Output: 0
 * Explanation:  Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * grid[i][j] is only 0, 1, or 2.
 *
 *
 *
 *
 */

#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution1 {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        // 先统计所有好的和坏的数量
        int good = 0, bad = 0;
        int width = grid[0].size();
        int height = grid.size();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 1) {
                    good++;
                } else if (grid[i][j] == 2) {
                    bad++;
                }
            }
        }
        if (good == 0) {
            return 0;
        }
        if (bad == 0) {
            return -1;
        }

        int newBad = 0;
        int time = 0;
        do {
            time++;
            newBad = 0;
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (grid[i][j] == 2) {
                        // 找到一个坏的，开始污染周围的
                        // 上 i-1,j
                        if (i > 0 && grid[i - 1][j] == 1) {
                            grid[i - 1][j] = 3;
                            newBad++;
                            good--;
                        }
                        // 下 i+1,j
                        if (i < height - 1 && grid[i + 1][j] == 1) {
                            grid[i + 1][j] = 3;
                            newBad++;
                            good--;
                        }
                        // 左 i,j-1
                        if (j > 0 && grid[i][j - 1] == 1) {
                            grid[i][j - 1] = 3;
                            newBad++;
                            good--;
                        }
                        // 右 i,j+1
                        if (j < width - 1 && grid[i][j + 1] == 1) {
                            grid[i][j + 1] = 3;
                            newBad++;
                            good--;
                        }
                    }
                }
            }
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (grid[i][j] == 3) {
                        grid[i][j] = 2;
                    }
                }
            }
        } while (newBad > 0);

        if (good > 0) {
            return -1;
        }
        return time - 1;
    }
};
// @lc code=start
class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        int width = grid[0].size();
        int height = grid.size();
        queue<pair<int, int>> badQueue;
        multiset<pair<int, int>> goodSet;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 1) {
                    goodSet.insert({i, j});
                } else if (grid[i][j] == 2) {
                    badQueue.push({i, j});
                }
            }
        }
        if (goodSet.size() == 0) {
            return 0;
        }
        if (badQueue.size() == 0) {
            return -1;
        }
        int time = 0;
        while (!badQueue.empty()) {
            int tmpSize = badQueue.size();
            int flag = 0;
            for (int i = 0; i < tmpSize; i++) {
                auto b = badQueue.front();
                badQueue.pop();
                vector<pair<int, int>> vecPair = {make_pair(b.first - 1, b.second), make_pair(b.first + 1, b.second),
                                                  make_pair(b.first, b.second - 1), make_pair(b.first, b.second + 1)};
                for (auto p : vecPair) {
                    if (goodSet.find(p) != goodSet.end()) {
                        goodSet.erase(p);
                        badQueue.push(p);
                        flag = 1;
                    }
                }
            }
            if (flag)
                time++;
        }
        if (goodSet.size() > 0)
            return -1;
        return time;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    // vector<vector<int>> grid = {{1, 2}};
    int time = s.orangesRotting(grid);
    return 0;
}
