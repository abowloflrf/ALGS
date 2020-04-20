/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 *
 * https://leetcode.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (33.45%)
 * Likes:    1519
 * Dislikes: 49
 * Total Accepted:    92.2K
 * Total Submissions: 293.7K
 * Testcase Example:  '"()"'
 *
 *
 * Given a string containing only three types of characters: '(', ')' and '*',
 * write a function to check whether this string is valid. We define the
 * validity of a string by these rules:
 *
 * Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left
 * parenthesis '(' or an empty string.
 * An empty string is also valid.
 *
 *
 *
 * Example 1:
 *
 * Input: "()"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "(*)"
 * Output: True
 *
 *
 *
 * Example 3:
 *
 * Input: "(*))"
 * Output: True
 *
 *
 *
 * Note:
 *
 * The string size will be in the range [1, 100].
 *
 *
 */
#include <stack>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool checkValidString(string s) {
        vector<int> S1;
        vector<int> star;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                S1.push_back(i);
            } else if (s[i] == '*') {
                star.push_back(i);
            } else {
                if (!S1.empty()) {
                    S1.pop_back();
                } else if (!star.empty()) {
                    star.pop_back();
                } else {
                    return false;
                }
            }
        }
        if (S1.size() > star.size())
            return false;
        // 关键部分，从后往前判断，*数量是否能够抵消(
        for (int i = S1.size() - 1; i >= 0; i--) {
            if (star.back() < S1.back())
                return false;
            star.pop_back();
            S1.pop_back();
        }
        return true;
    }
};
// @lc code=end

// 这个答案真简洁。。。
class Solution2 {
  public:
    bool checkValidString(string s) {
        // 遍历时记录剩余左括号做多的数量和可能剩余最少的数量
        int lbLeftLow = 0;
        int lbLeftHigh = 0;
        for (auto c : s) {
            lbLeftLow += c == '(' ? 1 : -1;  // 遇到 ) 和 * 都-1，永远把*当)来抵消
            lbLeftHigh += c == ')' ? -1 : 1; // 遇到 ) 才-1
            if (lbLeftHigh < 0) {
                return false;
            }
            lbLeftLow = max(lbLeftLow, 0);
        }
        return lbLeftLow == 0;
    }
};

int main() {
    Solution s;
    bool r = s.checkValidString("(())((())()()(*)(*()(())())())()()((()())((()))(*");
    return 0;
}
