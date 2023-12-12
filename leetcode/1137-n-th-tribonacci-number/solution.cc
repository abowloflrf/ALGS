/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 *
 * https://leetcode.cn/problems/n-th-tribonacci-number/description/
 *
 * algorithms
 * Easy (60.94%)
 * Likes:    291
 * Dislikes: 0
 * Total Accepted:    181.4K
 * Total Submissions: 297.6K
 * Testcase Example:  '4'
 *
 * The Tribonacci sequence Tn is defined as follows: 
 *
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 *
 * Given n, return the value of Tn.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: 4
 * Explanation:
 * T_3 = 0 + 1 + 1 = 2
 * T_4 = 1 + 1 + 2 = 4
 *
 *
 * Example 2:
 *
 *
 * Input: n = 25
 * Output: 1389537
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 37
 * The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31
 * - 1.
 *
 */

// @lc code=start
class Solution {
  public:
    int tribonacci(int n) {
        int f1 = 0;
        int f2 = 1;
        int f3 = 1;
        if (n == 0)
            return 0;
        if (n < 3) {
            return 1;
        }
        while (n-- - 3) {
            int tmp = f1;
            f1 = f2;
            f2 = f3;
            f3 = tmp + f1 + f2;
        }
        return f3;
    }
};
// @lc code=end
