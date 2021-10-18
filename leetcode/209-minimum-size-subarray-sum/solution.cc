/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (47.34%)
 * Likes:    789
 * Dislikes: 0
 * Total Accepted:    200.9K
 * Total Submissions: 424.4K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a contiguous subarray [numsl, numsl+1, ...,
 * numsr-1, numsr] of which the sum is greater than or equal to target. If
 * there is no such subarray, return 0 instead.
 *
 *
 * Example 1:
 *
 *
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 *
 * Example 2:
 *
 *
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution of which the time complexity is O(n log(n)).
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int start = 0, end = 0;
        int current = 0;
        int ans = INT32_MAX;
        while (end < nums.size()) {
            current += nums[end];
            while (current >= target) {
                ans = min(ans, end - start + 1);
                // 考虑到数组特性，start 其实一定不会超过 end，若到达 end 处则一定会跳出 while 循环继续加 end
                current -= nums[start++];
            }
            end++;
        }
        if (ans == INT32_MAX)
            return 0;
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> v = {2, 3, 1, 2, 4, 3};
    s.minSubArrayLen(7, v);
    return 0;
}
