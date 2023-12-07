/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 *
 * https://leetcode.cn/problems/greatest-common-divisor-of-strings/description/
 *
 * algorithms
 * Easy (57.89%)
 * Likes:    371
 * Dislikes: 0
 * Total Accepted:    67.9K
 * Total Submissions: 117.3K
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * For two strings s and t, we say "t divides s" if and only if s = t + ... + t
 * (i.e., t is concatenated with itself one or more times).
 *
 * Given two strings str1 and str2, return the largest string x such that x
 * divides both str1 and str2.
 *
 *
 * Example 1:
 *
 *
 * Input: str1 = "ABCABC", str2 = "ABC"
 * Output: "ABC"
 *
 *
 * Example 2:
 *
 *
 * Input: str1 = "ABABAB", str2 = "ABAB"
 * Output: "AB"
 *
 *
 * Example 3:
 *
 *
 * Input: str1 = "LEET", str2 = "CODE"
 * Output: ""
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of English uppercase letters.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    string gcdOfStrings(string str1, string str2) {
        // 如果两字符前后连接不相等，说明不存在公共字符串
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }

    // 最大公因子算法 gcd
    int gcd(int a, int b) { return 0 == b ? a : gcd(b, a % b); }
};
// @lc code=end

// 最大公因子算法 gcd
// int gcd(a, b) => (0 == b ? a : gcd(b, a % b))
