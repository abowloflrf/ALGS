/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 *
 * https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/description/
 *
 * algorithms
 * Easy (80.75%)
 * Likes:    109
 * Dislikes: 0
 * Total Accepted:    42.6K
 * Total Submissions: 52.7K
 * Testcase Example:  '"RLRRLLRLRL"'
 *
 * Balanced strings are those that have an equal quantity of 'L' and 'R'
 * characters.
 *
 * Given a balanced string s, split it in the maximum amount of balanced
 * strings.
 *
 * Return the maximum amount of split balanced strings.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "RLRRLLRLRL"
 * Output: 4
 * Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring
 * contains same number of 'L' and 'R'.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "RLLLLRRRLR"
 * Output: 3
 * Explanation: s can be split into "RL", "LLLRRR", "LR", each substring
 * contains same number of 'L' and 'R'.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "LLLLRRRR"
 * Output: 1
 * Explanation: s can be split into "LLLLRRRR".
 *
 *
 * Example 4:
 *
 *
 * Input: s = "RLRRRLLRLL"
 * Output: 2
 * Explanation: s can be split into "RL", "RRRLLRLL", since each substring
 * contains an equal number of 'L' and 'R'
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s[i] is either 'L' or 'R'.
 * s is a balanced string.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    int balancedStringSplit(string s) {
        int rn = 0, ln = 0;
        int ans = 0;
        for (char c : s) {
            if (c == 'R')
                rn++;
            else
                ln++;
            if (rn == ln) {
                ans++;
                rn = 0;
                ln = 0;
            }
        }
        return ans;
    }
};
// @lc code=end
