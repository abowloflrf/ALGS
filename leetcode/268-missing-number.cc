/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (49.46%)
 * Likes:    1513
 * Dislikes: 1885
 * Total Accepted:    410.5K
 * Total Submissions: 809K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 *
 * Example 1:
 *
 *
 * Input: [3,0,1]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 *
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        const int n = nums.size();
        int targetSum = (1 + n) * n / 2;
        for (int n : nums) {
            targetSum-=n;
        }
        return targetSum;
    }
};
// @lc code=end
