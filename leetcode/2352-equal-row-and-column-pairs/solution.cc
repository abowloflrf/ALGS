/*
 * @lc app=leetcode.cn id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 *
 * https://leetcode.cn/problems/equal-row-and-column-pairs/description/
 *
 * algorithms
 * Medium (73.30%)
 * Likes:    87
 * Dislikes: 0
 * Total Accepted:    41.4K
 * Total Submissions: 56.4K
 * Testcase Example:  '[[3,2,1],[1,7,6],[2,7,7]]'
 *
 * Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri,
 * cj) such that row ri and column cj are equal.
 *
 * A row and column pair is considered equal if they contain the same elements
 * in the same order (i.e., an equal array).
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
 * Output: 1
 * Explanation: There is 1 equal row and column pair:
 * - (Row 2, Column 1): [2,7,7]
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
 * Output: 3
 * Explanation: There are 3 equal row and column pairs:
 * - (Row 0, Column 0): [3,1,2,2]
 * - (Row 2, Column 2): [2,4,2,2]
 * - (Row 3, Column 2): [2,4,2,2]
 *
 *
 *
 * Constraints:
 *
 *
 * n == grid.length == grid[i].length
 * 1 <= n <= 200
 * 1 <= grid[i][j] <= 10^5
 *
 *
 */
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int equalPairs(vector<vector<int>> &grid) {
        int ans = 0;
        vector<vector<int>> transGrid;
        for (int i = 0; i < grid.size(); i++) {
            vector<int> col;
            for (int j = 0; j < grid.size(); j++) {
                col.push_back(grid[j][i]);
            }
            transGrid.push_back(col);
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i] == transGrid[j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

// 用哈希表，空间换时间方法
class Solution2 {
  public:
    int equalPairs(vector<vector<int>> &grid) {
        // 这里只能用 map 而不能用 unordered_map 因为
        // unordered_map 内部实现为哈希表，需要 key 是可 hash 的
        // map 实现时红黑树，内部 key 可以比较即可，vector 是可比较的
        // tips: 如果不想考虑吧 vector 当 key 这么复杂，可直接吧一行转位字符串当作 key
        // 但是需要考虑 11-1 和 1-11 的区别，最好用特殊字符连接。
        map<vector<int>, int> row;
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            row[grid[i]]++;
        }
        for (int i = 0; i < grid.size(); i++) {
            vector<int> tmp;
            for (int j = 0; j < grid.size(); j++) {
                tmp.push_back(grid[j][i]);
            }
            ans += row[tmp];
        }
        return ans;
    }
};