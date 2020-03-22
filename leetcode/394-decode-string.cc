/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (46.88%)
 * Likes:    2534
 * Dislikes: 129
 * Total Accepted:    173.1K
 * Total Submissions: 358.7K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 *
 * Examples:
 *
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 *
 *
 *
 *
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    string decodeString(string s) { return dfs(s, 0).second; }

  private:
    pair<int, string> dfs(string &s, int i) {
        int repeatNum = 0;
        string res;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                // 数字
                repeatNum = repeatNum * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                // 括号开，开始计算需要重复的部分
                auto p = dfs(s, i + 1);
                i = p.first;
                while (repeatNum--) {
                    res += p.second;
                }
                repeatNum = 0;
            } else if (s[i] == ']') {
                // 括号闭
                return make_pair(i, res);
            } else {
                // 字母
                res.push_back(s[i]);
            }
            i++;
        }
        return make_pair(0, res);
    }
};
// @lc code=end

class Solution2 {
  public:
    string decodeString(string s) {
        //两个栈，一个放需要重复的部分，一个放重复次数
        string res = "";
        int repeatNum = 0;
        stack<string> stackRes;
        stack<int> stackNum;
        for (char c : s) {
            if (isdigit(c)) {
                repeatNum = repeatNum * 10 + c - '0';
            } else if (c == '[') {
                stackRes.push(res);
                stackNum.push(repeatNum);
                repeatNum = 0;
                res = "";
            } else if (c == ']') {
                int n = stackNum.top();
                string last = stackRes.top();
                stackNum.pop();
                stackRes.pop();
                while (n--) {
                    last += res;
                }
                res = last;
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};

int main() {
    Solution2 s;
    string res = s.decodeString("2[abc]3[cd]ef");
    return 0;
}
