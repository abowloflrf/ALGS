/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (77.03%)
 * Likes:    667
 * Dislikes: 0
 * Total Accepted:    200.9K
 * Total Submissions: 260.9K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of the range [1, n].
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr = {};
        dfs(n, k, 1, curr);
        return res;
    }

    // start 当前判断到第几个，只会取从 start 开始后面的数字
    void dfs(int n, int k, int start, vector<int> &curr) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            dfs(n, k, i + 1, curr);
            curr.pop_back();
        }
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    auto ans = s.combine(5, 3);
    return 0;
}
