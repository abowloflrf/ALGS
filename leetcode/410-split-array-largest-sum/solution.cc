/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 *
 * https://leetcode-cn.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (56.49%)
 * Likes:    560
 * Dislikes: 0
 * Total Accepted:    39.6K
 * Total Submissions: 70.1K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * Given an array nums which consists of non-negative integers and an integer
 * m, you can split the array into m non-empty continuous subarrays.
 *
 * Write an algorithm to minimize the largest sum among these m subarrays.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [7,2,5,10,8], m = 2
 * Output: 18
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4,5], m = 2
 * Output: 9
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,4,4], m = 3
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 10^6
 * 1 <= m <= min(50, nums.length)
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int splitArray(vector<int> &nums, int m) {
        int left = 0;
        int right = 0;
        for (int n : nums) {
            left = max(n, left);
            right += n;
        }

        // 在 right left 作为左右边界使用二分查找满足小于目标 m
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 选择目标和为 mid 时，从前往后模拟，计算分成的最少块数
            int currentParts = 1;
            int currentSum = 0;
            for (int n : nums) {
                if (currentSum + n > mid) {
                    currentParts++;
                    currentSum = n;
                } else {
                    currentSum += n;
                }
            }
            if (currentParts <= m) {
                // 小于或等于目标，满足要求，mid 不要减一，否则可能就不满足了
                right = mid;
            } else {
                // 大于目标，不满足要求
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
