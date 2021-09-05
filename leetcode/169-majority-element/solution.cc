/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (66.17%)
 * Likes:    1036
 * Dislikes: 0
 * Total Accepted:    330.3K
 * Total Submissions: 499.2K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array nums of size n, return the majority element.
 *
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 *
 *
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
 */
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// map 计数
class Solution02 {
  public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> m;
        for (auto const &n : nums) {
            m[n]++;
            if (m[n] > nums.size() / 2) {
                return n;
            }
        }
        return -1;
    }
};

// 排序法
class Solution03 {
  public:
    int majorityElement(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// @lc code=start
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int candidate = nums[0];
        int count = 0;
        for (auto const &n : nums) {
            if (count == 0) {
                candidate = n;
            }
            if (candidate == n) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};
// @lc code=end
