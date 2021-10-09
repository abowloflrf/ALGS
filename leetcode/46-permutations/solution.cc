/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (78.21%)
 * Likes:    1509
 * Dislikes: 0
 * Total Accepted:    391.9K
 * Total Submissions: 501.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        helper(nums, 0, result);
        return result;
    }

  private:
    // helper nums 的前 index 位确定的情况下，获取全排列的情况
    void helper(vector<int> &nums, int index, vector<vector<int>> &res) {
        if (index == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        // 前 index 位都确定，因此第 index 位可能为后面所有数的情况，因此依次交换确定 index 位后递归调用
        for (int i = index; i < nums.size(); i++) {
            if (i == index) {
                helper(nums, index + 1, res);
            } else {
                swap(nums[index], nums[i]);
                helper(nums, index + 1, res);
                swap(nums[index], nums[i]);
            }
        }
    }
};
// @lc code=end
