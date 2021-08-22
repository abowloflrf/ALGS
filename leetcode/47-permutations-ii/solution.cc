/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (63.59%)
 * Likes:    778
 * Dislikes: 0
 * Total Accepted:    200.6K
 * Total Submissions: 315.4K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> result;
        helper(nums, 0, result);
        return result;
    }

  private:
    void helper(vector<int> &nums, int index, vector<vector<int>> &res) {
        if (index == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        // 相比 LC46，需要额外剪枝，使用一个set记录首位出现过的独立的数字集合
        unordered_set<int> used;
        for (int i = index; i < nums.size(); i++) {
            if (i == index) {
                used.insert(nums[i]);
                helper(nums, index + 1, res);
            } else {
                // 目标交换的数字已经在首位出现过使用过，即之前就交换过相同的数字
                if (used.find(nums[i]) != used.end())
                    continue;
                used.insert(nums[i]);
                swap(nums[index], nums[i]);
                helper(nums, index + 1, res);
                swap(nums[index], nums[i]);
            }
        }
    }
};
// @lc code=end
