/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.88%)
 * Likes:    6938
 * Dislikes: 318
 * Total Accepted:    908K
 * Total Submissions: 2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */

#include <vector>
using namespace std;

/**
 * 1. 贪心
 * 2. 动态规划
 **/

// @lc code=start
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int res = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // 要么要这个数与前面序列和相加，要么只要这个数，取较大的
            currentSum = max(currentSum + nums[i], nums[i]);
            // 维护最大值
            res = max(currentSum, res);
        }
        return res;
    }
};
// @lc code=end
