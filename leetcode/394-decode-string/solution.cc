/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.cn/problems/decode-string/description/
 *
 * algorithms
 * Medium (57.07%)
 * Likes:    1642
 * Dislikes: 0
 * Total Accepted:    276.4K
 * Total Submissions: 484.3K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; there are no extra
 * white spaces, square brackets are well-formed, etc. Furthermore, you may
 * assume that the original data does not contain any digits and that digits
 * are only for those repeat numbers, k. For example, there will not be input
 * like 3a or 2[4].
 *
 * The test cases are generated so that the length of the output will never
 * exceed 10^5.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 *
 *
 */
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    string decodeString(string s) {
        string ans;
        stack<string> stkStr;
        stack<int> stkNum;
        int num = 0;
        for (auto c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                stkNum.push(num);
                stkStr.push(ans);
                ans = "";
                num = 0;
            } else if (c == ']') {
                int n = stkNum.top();
                string str = stkStr.top();
                while (n--) {
                    str += ans;
                }
                ans = str;
                stkNum.pop();
                stkStr.pop();
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
// @lc code=end
