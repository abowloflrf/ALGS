/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (18.23%)
 * Likes:    909
 * Dislikes: 2721
 * Total Accepted:    374.9K
 * Total Submissions: 1.9M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 *
 *
 * Example 2:
 *
 *
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 *
 *
 * Example 3:
 *
 *
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 *
 *
 *
 *
 * Note:
 *
 *
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 *
 *
 *
 *
 * Follow up:
 *
 * For C programmers, try to solve it in-place in O(1) extra space.
 */
#include <stack>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    string reverseWords(string s) {
        stack<string> S;
        string word;
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    S.push(word);
                    word.clear();
                }
            } else {
                word.push_back(c);
            }
        }
        // 记得最后一个单词要入栈
        if (!word.empty()) {
            S.push(word);
        }
        string res;
        while (!S.empty()) {
            res += S.top();
            res.push_back(' ');
            S.pop();
        }
        // 记得删掉最后多的一个空格
        if (!res.empty() && res.back() == ' ')
            res.pop_back();
        return res;
    }
};
// @lc code=end

int main() {
    Solution s;
    string input = "  hello world!  ";
    string r = s.reverseWords(input);
    return 0;
}