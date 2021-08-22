/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (72.67%)
 * Likes:    1487
 * Dislikes: 0
 * Total Accepted:    312.1K
 * Total Submissions: 429.5K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 *
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 *
 * It is guaranteed that the number of unique combinations that sum up to
 * target is less than 150 combinations for the given input.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 *
 *
 * Example 3:
 *
 *
 * Input: candidates = [2], target = 1
 * Output: []
 *
 *
 * Example 4:
 *
 *
 * Input: candidates = [1], target = 1
 * Output: [[1]]
 *
 *
 * Example 5:
 *
 *
 * Input: candidates = [1], target = 2
 * Output: [[1,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        helper(candidates, target, path, 0, res);
        return res;
    }

  private:
    void helper(vector<int> &candidates, int target, vector<int> &path, int index, vector<vector<int>> &res) {
        int currentSum = 0;
        for (int i = 0; i < path.size(); i++) {
            currentSum += path[i];
        }
        if (currentSum == target) {
            res.push_back(path);
            return;
        }

        // 继续取数
        for (int i = index; i < candidates.size(); i++) {
            if (currentSum + candidates[i] > target) {
                continue;
            }
            path.push_back(candidates[i]);
            helper(candidates, target, path, i, res);
            path.pop_back();
        }
    }
};
// @lc code=end
