/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] Power of Two
 *
 * https://leetcode-cn.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (50.34%)
 * Likes:    399
 * Dislikes: 0
 * Total Accepted:    158.9K
 * Total Submissions: 315.7K
 * Testcase Example:  '1'
 *
 * Given an integer n, return true if it is a power of two. Otherwise, return
 * false.
 *
 * An integer n is a power of two, if there exists an integer x such that n ==
 * 2^x.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 1
 * Output: true
 * Explanation: 2^0 = 1
 *
 *
 * Example 2:
 *
 *
 * Input: n = 16
 * Output: true
 * Explanation: 2^4 = 16
 *
 *
 * Example 3:
 *
 *
 * Input: n = 3
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: n = 4
 * Output: true
 *
 *
 * Example 5:
 *
 *
 * Input: n = 5
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= n <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you solve it without loops/recursion?
 */

// @lc code=start
class Solution {
  public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        while (n > 1) {
            if (n % 2 == 1)
                return false;
            n /= 2;
        }
        return true;
    }
};
// @lc code=end
