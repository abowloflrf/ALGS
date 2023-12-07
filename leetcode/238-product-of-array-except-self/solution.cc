/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.cn/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (74.95%)
 * Likes:    1650
 * Dislikes: 0
 * Total Accepted:    345.7K
 * Total Submissions: 461.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 *
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 * You must write an algorithm that runs in O(n) time and without using the
 * division operation.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 *
 *
 * Follow up: Can you solve the problem in O(1) extra space complexity? (The
 * output array does not count as extra space for space complexity analysis.)
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        // 从左到右和从右到左分别走两遍，累计乘当前数所有左边和右边数的乘积
        vector<int> answer(nums.size(), 1);
        int left = 1;
        // 下面循环后 answer[i] 为 i 所有左边数的乘积
        for (int i = 0; i < nums.size(); i++) {
            answer[i] *= left;
            left *= nums[i];
        }
        // 下面循环后 answer[i] 又乘上了 i 所有右边数的乘积
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            answer[i] *= right;
            right *= nums[i];
        }
        return answer;
    }
};
// @lc code=end
