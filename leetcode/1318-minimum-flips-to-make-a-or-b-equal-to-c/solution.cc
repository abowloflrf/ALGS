/*
 * @lc app=leetcode.cn id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 *
 * https://leetcode.cn/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
 *
 * algorithms
 * Medium (67.65%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    13.2K
 * Total Submissions: 19.5K
 * Testcase Example:  '2\n6\n5'
 *
 * Given 3 positives numbers a, b and c. Return the minimum flips required in
 * some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
 * Flip operation consists of change any single bit 1 to 0 or change the bit 0
 * to 1 in their binary representation.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: a = 2, b = 6, c = 5
 * Output: 3
 * Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
 *
 * Example 2:
 *
 *
 * Input: a = 4, b = 2, c = 7
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: a = 1, b = 2, c = 3
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= a <= 10^9
 * 1 <= b <= 10^9
 * 1 <= c <= 10^9
 *
 */

// @lc code=start
class Solution {
  public:
    int minFlips(int a, int b, int c) {

        int ans = 0;
        while (a || b || c) {
            int aa = a % 2, bb = b % 2, cc = c % 2;
            if (cc == 0) {
                if (aa == 1)
                    ans++;
                if (bb == 1)
                    ans++;
            }
            if (cc == 1) {
                if (aa == 0 && bb == 0)
                    ans++;
            }
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return ans;
    }
};
// @lc code=end
