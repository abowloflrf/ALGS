/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (41.56%)
 * Likes:    3776
 * Dislikes: 86
 * Total Accepted:    320.6K
 * Total Submissions: 764.4K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 *
 * Example:
 *
 *
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 *
 * Note:
 *
 *
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 *
 *
 * Follow up: Could you improve it to O(n log n) time complexity?
 *
 */

#include <vector>
using namespace std;
// @lc code=start
// dp(n) 为 前n个元素的序列中必取第n个元素时最长递增子序列的长度
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        int dp[nums.size()];
        // vector<int> dp = vector<int>(nums.size(), 1);
        int res = 1;
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> v = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    Solution s;
    int r = s.lengthOfLIS(v);
    return 0;
}