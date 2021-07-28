/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (55.83%)
 * Likes:    2477
 * Dislikes: 60
 * Total Accepted:    434.9K
 * Total Submissions: 777.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res{{}};
        for (auto n : nums) {
            vector<vector<int>> added;
            int sizeR = res.size();
            for (int i = 0; i < sizeR; i++) {
                vector<int> newRes(res[i]);
                newRes.push_back(n);
                res.push_back(newRes);
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> vec{1, 2, 3};
    Solution s;
    auto r = s.subsets(vec);
    return 0;
}
