/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (48.43%)
 * Likes:    1189
 * Dislikes: 97
 * Total Accepted:    352.6K
 * Total Submissions: 692.7K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i++) {
            if (i == 1) {
                res.push_back({1});
            } else if (i == 2) {
                res.push_back({1, 1});
            } else {
                vector<int> level;
                level.push_back(1);
                for (int i = 0; i < res.back().size() - 1; i++) {
                    level.push_back(res.back()[i] + res.back()[i + 1]);
                }
                level.push_back(1);
                res.push_back(level);
            }
        }
        return res;
    }
};
// @lc code=end
