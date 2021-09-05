/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode-cn.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (48.97%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    94.5K
 * Total Submissions: 193K
 * Testcase Example:  '27'
 *
 * Given an integer n, return true if it is a power of three. Otherwise, return
 * false.
 *
 * An integer n is a power of three, if there exists an integer x such that n
 * == 3^x.
 *
 *
 * Example 1:
 * Input: n = 27
 * Output: true
 * Example 2:
 * Input: n = 0
 * Output: false
 * Example 3:
 * Input: n = 9
 * Output: true
 * Example 4:
 * Input: n = 45
 * Output: false
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
    bool isPowerOfThree(int n) {
        if (n == 0)
            return false;
        long tmp = 1;
        while (tmp <= n) {
            if (tmp == n) {
                return true;
            }
            tmp *= 3;
        }
        return false;
    }
};
// @lc code=end

class Solution2 {
  public:
    bool isPowerOfThree(int n) {
        // 1162261467 = 3^19 是 int 内最大的 3 的次幂
        return n > 0 && (1162261467 % n == 0);
    }
};
