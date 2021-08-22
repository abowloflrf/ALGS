/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (62.92%)
 * Likes:    672
 * Dislikes: 0
 * Total Accepted:    187.7K
 * Total Submissions: 298.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note: The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */
#include <algorithm>
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
    void helper(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &comb, int idx) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        for (int i = idx; i != candidates.size() && target >= candidates[i]; i++) {
            // 这个剪枝非常关键，由于已经排好序了，连续两次选择两个相同的数字是没有必要的
            if (i == idx || candidates[i] != candidates[i - 1]) {
                comb.push_back(candidates[i]);
                helper(candidates, target - candidates[i], res, comb, i + 1);
                comb.pop_back();
            }
        }
    }
};
// @lc code=end
