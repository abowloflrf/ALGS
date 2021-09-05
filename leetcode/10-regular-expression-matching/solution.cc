/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (31.64%)
 * Likes:    2343
 * Dislikes: 0
 * Total Accepted:    198.5K
 * Total Submissions: 627.4K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*' where:
 *
 *
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 * Example 4:
 *
 *
 * Input: s = "aab", p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 *
 *
 * Example 5:
 *
 *
 * Input: s = "mississippi", p = "mis*is*p*."
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 20
 * 1 <= p.length <= 30
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a
 * previous valid character to match.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();

        // 目标字符串的第一位是否匹配
        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');

        // .* 可以匹配零个或多个任意字符
        // 一旦存在 *，想要消除必须是 x* 连续的两位一起消除
        // 第二位是 *，可选择匹配或不匹配
        if (p.size() > 1 && p[1] == '*') {
            // 使用 *（首位可以匹配或不匹配）
            //   [a...]和[b*...] -> [...] [...]
            // 暂不使用 *（首位必须要匹配）
            //   [a...]和[a*...] -> [...] [a*...]
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        }
        return firstMatch && isMatch(s.substr(1), p.substr(1));
    }
};
// @lc code=end
