/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] Add Digits
 *
 * https://leetcode-cn.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (69.14%)
 * Likes:    360
 * Dislikes: 0
 * Total Accepted:    75.7K
 * Total Submissions: 109.5K
 * Testcase Example:  '38'
 *
 * Given an integer num, repeatedly add all its digits until the result has
 * only one digit, and return it.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 38
 * Output: 2
 * Explanation: The process is
 * 38 --> 3 + 8 --> 11
 * 11 --> 1 + 1 --> 2
 * Since 2 has only one digit, return it.
 *
 *
 * Example 2:
 *
 *
 * Input: num = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= num <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you do it without any loop/recursion in O(1) runtime?
 *
 */

// @lc code=start
class Solution {
  public:
    int addDigits(int num) {
        while (num >= 10) {
            int tmpSum = 0;
            int tmpNum = num;
            while (tmpNum > 0) {
                tmpSum += tmpNum % 10;
                tmpNum /= 10;
            }
            num = tmpSum;
        }
        return num;
    }
};
// @lc code=end
