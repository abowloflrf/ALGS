/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 *
 * https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
 *
 * algorithms
 * Medium (65.09%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    45.3K
 * Total Submissions: 69.6K
 * Testcase Example:  '"(abcd)"'
 *
 * You are given a string s that consists of lower case English letters and
 * brackets. 
 *
 * Reverse the strings in each pair of matching parentheses, starting from the
 * innermost one.
 *
 * Your result should not contain any brackets.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(abcd)"
 * Output: "dcba"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "(u(love)i)"
 * Output: "iloveu"
 * Explanation: The substring "love" is reversed first, then the whole string
 * is reversed.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(ed(et(oc))el)"
 * Output: "leetcode"
 * Explanation: First, we reverse the substring "oc", then "etco", and finally,
 * the whole string.
 *
 *
 * Example 4:
 *
 *
 * Input: s = "a(bcdefghijkl(mno)p)q"
 * Output: "apmnolkjihgfedcbq"
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 2000
 * s only contains lower case English characters and parentheses.
 * It's guaranteed that all parentheses are balanced.
 *
 *
 */
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    string reverseParentheses(string s) {
        stack<pair<char, int>> ps; // <'(',1> <')',2>
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == ')') {
                if (ps.empty()) {
                    ps.push({s[i], i});
                } else if (ps.top().first == '(' && s[i] == ')') {
                    // 反转
                    auto t = ps.top();
                    ps.pop();
                    // reverse(a,b) 反转不包括迭代器b指向的内容
                    reverse(s.begin() + t.second, s.begin() + i + 1);
                    // 将括号标记删除
                    s[t.second] = '-';
                    s[i] = '-';
                } else {
                    ps.push({s[i], i});
                }
            }
        }
        // 删除标记的括号
        for (int i = 0; i < s.size();) {
            if (s[i] == '-') {
                s.erase(s.begin() + i);
            } else {
                i++;
            }
        }
        return s;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    Solution s;
    s.reverseParentheses("(abcd)");
    return 0;
}
