/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (37.68%)
 * Likes:    727
 * Dislikes: 0
 * Total Accepted:    210.6K
 * Total Submissions: 558.8K
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (i.e.,
 * x^n).
 *
 *
 * Example 1:
 *
 *
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 *
 *
 * Example 2:
 *
 *
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 *
 *
 * Example 3:
 *
 *
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 *
 *
 *
 * Constraints:
 *
 *
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * -10^4 <= x^n <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
  public:
    double myPow(double x, int n) { return fastpow(x, n); }

  private:
    double fastpow(double x, long n) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 1 / fastpow(x, -n);

        double res = fastpow(x, n / 2);
        if (n % 2) {
            return res * res * x;
        } else {
            return res * res;
        }
    }
};
// @lc code=end
