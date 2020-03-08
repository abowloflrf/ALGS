/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (33.67%)
 * Likes:    3108
 * Dislikes: 104
 * Total Accepted:    325.1K
 * Total Submissions: 965.4K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 *
 * Example 1:
 *
 *
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 * Example 2:
 *
 *
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 *
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 *
 */

#include <bits/stdc++.h>

using namespace std;

// 根据状态转移方程
// 暴力求解，有重复计算的部分
// 但是会超时
class Solution1 {
  public:
    int dp(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        int res = INT32_MAX;
        for (auto coin : coins) {
            // 子问题求解
            int sub = dp(coins, amount - coin);
            if (sub == -1)
                continue;
            res = min(res, sub + 1);
        }
        return res;
    }
    int coinChange(vector<int> &coins, int amount) {
        if (amount < 1)
            return 0;
        return dp(coins, amount);
    }
};
// @lc code=start
// 用一个map保存已经运算过的子问题的解
class Solution {
  public:
    int dp(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        int res = INT32_MAX;
        for (auto coin : coins) {
            // 子问题求解
            int sub;
            // 先在已解决的 solved map 中寻找，避免重复计算
            if (solved.find(amount - coin) != solved.end())
                sub = solved[amount - coin];
            else
                sub = dp(coins, amount - coin);
            if (sub == -1)
                continue;
            res = min(res, sub + 1);
        }
        if (res == INT32_MAX)
            res = -1;
        solved[amount] = res;
        return res;
    }
    int coinChange(vector<int> &coins, int amount) {
        if (amount < 1)
            return 0;
        return dp(coins, amount);
    }
    // 保存已解决的子问题的解
    unordered_map<int, int> solved;
};
// @lc code=end

// 使用 dp table 解
// dp[i] 表示金额为i时，需要的coin数量
class Solution3 {
  public:
    int coinChange(vector<int> &coins, int amount) {
        // 初始化为amount+1而不是INT32_MAX因为避免不了+1
        // 而因为coin都是整数，最小也是1，因此最大值只能是amount
        // 用amount+1代替INT32_MAX
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < dp.size(); i++) {
            for (int coin : coins) {
                if (i - coin < 0)
                    continue;
                dp[i] = min(dp[i - coin] + 1, dp[i]);
            }
        }
        if (dp[amount] == amount + 1)
            return -1;
        else
            return dp[amount];
    }
};