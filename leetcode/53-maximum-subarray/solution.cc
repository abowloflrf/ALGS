/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (55.15%)
 * Likes:    3658
 * Dislikes: 0
 * Total Accepted:    647K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * A subarray is a contiguous part of an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -10^5 <= nums[i] <= 10^5
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 *
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        // 1. 若取前 n-1 ，则直接连续上
        // 2. 若不取，则只取 N
        // 判断两种情况谁受益最大选谁
        int currentSum = nums[0];
        int ans = currentSum;
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i] + currentSum, nums[i]);
            ans = max(ans, currentSum);
        }
        return ans;
    }
};
// @lc code=end
