/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (30.25%)
 * Likes:    3258
 * Dislikes: 137
 * Total Accepted:    291.1K
 * Total Submissions: 942.4K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 *
 * Example 1:
 *
 *
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 *
 * Example 2:
 *
 *
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        int res = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(currentMax, currentMin);
            }
            currentMin = min(nums[i] * currentMin, nums[i]);
            currentMax = max(nums[i] * currentMax, nums[i]);
            res = max(res, currentMax);
        }
        return res;
    }
};
// @lc code=end
