/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (42.02%)
 * Likes:    1344
 * Dislikes: 1790
 * Total Accepted:    315.4K
 * Total Submissions: 739.6K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 *
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2,
 * or index number 5 where the peak element is 6.
 *
 *
 * Note:
 *
 * Your solution should be in logarithmic complexity.
 *
 */
#include <vector>
using namespace std;
// @lc code=start
// 线性扫描 O(n)
class Solution {
  public:
    int findPeakElement(vector<int> &nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.empty())
            return -1;
        int left = INT32_MIN;
        int right = nums[1];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > left && nums[i] < right)
                return i;
            left = nums[i];
            right = i == nums.size() ? INT32_MIN : nums[i + 2];
        }
        return -1;
    }
};
// @lc code=end

// 二分查找
class Solution2 {
  public:
    int findPeakElement(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1]) {
                if (mid == 0 || nums[mid - 1] < nums[mid])
                    return mid;
                r = mid;

            } else
                l = mid + 1;
        }
        return l;
    }
};
