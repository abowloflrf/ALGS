/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.65%)
 * Likes:    1126
 * Dislikes: 0
 * Total Accepted:    151.6K
 * Total Submissions: 339.4K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers nums and an integer k, return the total number of
 * continuous subarrays whose sum equals to k.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 *
 *
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int ans = 0;
        int prefixSum = 0;
        // 前缀和 value => count 的映射
        // 记得初始有 0->1
        unordered_map<int, int> h = {{0, 1}};
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            auto iter = h.find(prefixSum - k);
            if (iter != h.end()) {
                ans += iter->second;
            }
            h[prefixSum]++;
        }
        return ans;
    }
};
// @lc code=end
