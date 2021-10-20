/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (43.33%)
 * Likes:    804
 * Dislikes: 0
 * Total Accepted:    171.4K
 * Total Submissions: 395.6K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have a security system connected, and it
 * will automatically contact the police if two adjacent houses were broken
 * into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the
 * police.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2), because they are adjacent houses.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int ans = 0;

        // 不抢第一间
        int dp[nums.size()];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        ans = dp[nums.size() - 1];

        // 不抢最后一间
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size() - 1; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return max(ans, dp[nums.size() - 2]);
    }
};
// @lc code=end
