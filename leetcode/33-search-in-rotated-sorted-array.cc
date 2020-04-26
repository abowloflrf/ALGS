/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.29%)
 * Likes:    4384
 * Dislikes: 426
 * Total Accepted:    668.8K
 * Total Submissions: 2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        if (nums.empty())
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        // 这个while条件比较关键，left right之间至少要有一个数
        // 因为下面的逻辑都是假设将数组分为三个部分作比较的
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            // |   |  |      |
            //        +
            // |789|112234567|
            // 中间的数比最左边数小
            //若左数小于中间的数，说明0位置靠左
            if (nums[left] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
                // |      |  |   |
                //        +
                // |445566789|123|
                // 中间数比最左边数大
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        if (target == nums[left])
            return left;
        if (target == nums[right])
            return right;
        return -1;
    }
};
// @lc code=end
