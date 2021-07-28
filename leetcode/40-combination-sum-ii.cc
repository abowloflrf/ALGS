/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (44.01%)
 * Likes:    1461
 * Dislikes: 56
 * Total Accepted:    299.1K
 * Total Submissions: 646.6K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        helper(candidates, target, res, comb, 0);
        return res;
    }

  private:
    void helper(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> comb, int idx) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        if (candidates[idx] <= target) {
            // 不要这个数
            helper(candidates, target, res, comb, idx + 1);
            // 要这个数
            comb.push_back(candidates[idx]);
            helper(candidates, target - candidates[idx], res, comb, idx + 1);
        }
    }
};
// @lc code=end
