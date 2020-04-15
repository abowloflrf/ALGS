/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (51.38%)
 * Likes:    3220
 * Dislikes: 102
 * Total Accepted:    490.2K
 * Total Submissions: 906.7K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
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
        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                comb.push_back(candidates[i]);
                helper(candidates, target - candidates[i], res, comb, i);
                comb.pop_back();
            }
        }
    }
};
// @lc code=end
