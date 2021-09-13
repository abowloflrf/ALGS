/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 *
 * https://leetcode-cn.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (35.21%)
 * Likes:    286
 * Dislikes: 0
 * Total Accepted:    18.9K
 * Total Submissions: 53.7K
 * Testcase Example:  '"()"'
 *
 * Given a string s containing only three types of characters: '(', ')' and
 * '*', return true if s is valid.
 *
 * The following rules define a valid string:
 *
 *
 * Any left parenthesis '(' must have a corresponding right parenthesis
 * ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis
 * '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis
 * ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left
 * parenthesis '(' or an empty string "".
 *
 *
 *
 * Example 1:
 * Input: s = "()"
 * Output: true
 * Example 2:
 * Input: s = "(*)"
 * Output: true
 * Example 3:
 * Input: s = "(*))"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s[i] is '(', ')' or '*'.
 *
 *
 */
#include <stack>
#include <string>

using namespace std;
// @lc code=start
class Solution {
  public:
    bool checkValidString(string s) {
        stack<int> leftP;
        stack<int> star;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                leftP.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else {
                if (!leftP.empty()) {
                    leftP.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else {
                    return false;
                }
            }
        }
        if (star.size() < leftP.size())
            return false;
        while (!leftP.empty()) {
            if (leftP.top() < star.top()) {
                leftP.pop();
                star.pop();
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
