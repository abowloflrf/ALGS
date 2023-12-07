/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.cn/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (43.08%)
 * Likes:    327
 * Dislikes: 0
 * Total Accepted:    124.8K
 * Total Submissions: 289.6K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * You are given an integer array nums consisting of n elements, and an integer
 * k.
 *
 * Find a contiguous subarray whose length is equal to k that has the maximum
 * average value and return this value. Any answer with a calculation error
 * less than 10^-5 will be accepted.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,12,-5,-6,50,3], k = 4
 * Output: 12.75000
 * Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5], k = 1
 * Output: 5.00000
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= k <= n <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    double findMaxAverage(vector<int> &nums, int k) {
        int currentSum = 0;
        for (int i = 0; i < k; i++) {
            currentSum += nums[i];
        }
        int currentMax = currentSum;
        for (int i = k; i < nums.size(); i++) {
            currentSum = currentSum + nums[i] - nums[i - k];
            currentMax = max(currentMax, currentSum);
        }
        // float 会出错，只能用 double
        return double(currentMax) / double(k);
    }
};
// @lc code=end
int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> input = {1, 12, -5, -6, 50, 3};
    s.findMaxAverage(input, 4);
    return 0;
}
