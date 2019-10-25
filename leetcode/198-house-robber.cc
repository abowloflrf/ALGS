/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (41.39%)
 * Likes:    3148
 * Dislikes: 102
 * Total Accepted:    384.6K
 * Total Submissions: 929.1K
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 * Example 2:
 *
 *
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    int rob(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int tmp;
        int dp1 = 0;
        int dp2 = 0;
        // 滚动赋值，不用额外的空间了
        for (int i = 0; i < nums.size(); i++) {
            tmp = max(dp2 + nums[i], dp1);
            dp2 = dp1;
            dp1 = tmp;
        }
        return dp1;
    }
};
// @lc code=end

// 依然需要额外的空间，但是用一位数组循环计算
class Solution2 {
  public:
    int rob(vector<int> &nums) {
        const int n = nums.size();
        vector<int> dp(n, 0);
        // dp[i] 为抢前i个房子
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        if (n > 2) {
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
        }

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
// 需要额外的空间
class Solution3 {
  public:
    int rob(vector<int> &nums) {
        //初始化dp的一维数组
        const int n = nums.size();
        _m = vector<int>(n, -1);
        targets = &nums;
        return dp(n - 1);
    }

  private:
    // 对于nums中前个i房子 能得到最多的钱Î
    int dp(int i) {
        if (i < 0)
            return 0;
        if (_m[i] >= 0)
            return _m[i]; //已经计算过
        // 抢第i个房子则抢不了第i-1个了，结果是：dp(i-2)+nums[i]
        // 不抢第i个房子，结果是计算钱i-1个房子的结果：dp(i-1)
        _m[i] = max(dp(i - 2) + (*targets)[i], dp(i - 1));
        return _m[i];
    }
    const vector<int> *targets;
    vector<int> _m;
};