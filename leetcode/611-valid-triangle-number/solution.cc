/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 *
 * https://leetcode-cn.com/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (53.19%)
 * Likes:    313
 * Dislikes: 0
 * Total Accepted:    50.8K
 * Total Submissions: 95.6K
 * Testcase Example:  '[2,2,3,4]'
 *
 * Given an integer array nums, return the number of triplets chosen from the
 * array that can make triangles if we take them as side lengths of a
 * triangle.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,2,3,4]
 * Output: 3
 * Explanation: Valid combinations are:
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,2,3,4]
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int triangleNumber(vector<int> &nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        // 最长边为基准，作为第一条边
        for (int i = nums.size() - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    // 第二个边取 right
                    // 则第三个边从 left 向后直到 right-1 都满足
                    count = count + right - left;
                    right--;
                } else {
                    left++;
                }
            }
        }
        return count;
    }
};
// @lc code=end
