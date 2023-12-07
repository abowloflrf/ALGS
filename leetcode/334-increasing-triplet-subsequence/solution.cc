/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.cn/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (42.83%)
 * Likes:    787
 * Dislikes: 0
 * Total Accepted:    141.3K
 * Total Submissions: 329.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an integer array nums, return true if there exists a triple of indices
 * (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such
 * indices exists, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,4,5]
 * Output: true
 * Explanation: Any triplet where i < j < k is valid.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,4,3,2,1]
 * Output: false
 * Explanation: No triplet exists.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [2,1,5,0,4,6]
 * Output: true
 * Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4]
 * == 4 < nums[5] == 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you implement a solution that runs in O(n) time complexity
 * and O(1) space complexity?
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool increasingTriplet(vector<int> &nums) {
        if (nums.size() < 3) {
            return false;
        }
        // 从左到右遍历数组，维护左边部分第二大的数，只要找到比这个第二大数大的数则成功
        // 因为要维护第二大的数，因此还需要维护左边最小的数
        int one = INT_MAX, two = INT_MAX;
        for (int i : nums) {
            if (i > two) {
                return true;
            }
            if (i < one) {
                one = i;
            } else if (i > one && i < two) {
                two = i;
            }
        }
        return false;
    }
};
// @lc code=end
