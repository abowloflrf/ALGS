/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (34.85%)
 * Likes:    1124
 * Dislikes: 202
 * Total Accepted:    156.8K
 * Total Submissions: 437.7K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 *
 * Example 1:
 *
 *
 * Input: "3+2*2"
 * Output: 7
 *
 *
 * Example 2:
 *
 *
 * Input: " 3/2 "
 * Output: 1
 *
 * Example 3:
 *
 *
 * Input: " 3+5 / 2 "
 * Output: 5
 *
 *
 * Note:
 *
 *
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 *
 *
 */
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    int calculate(string s) {
        stack<int> numStack;

        int num = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0'); //这里有坑，必须要带括号，要不然有一个int溢出的case
            }
            // 注意遍历到最后一位时 i = s.size() - 1 要进行最后的运算操作
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1) {
                if (sign == '+') {
                    numStack.push(num);
                } else if (sign == '-') {
                    numStack.push(-num);
                } else if (sign == '*') {
                    int tmp = numStack.top();
                    numStack.pop();
                    numStack.push(tmp * num);
                } else if (sign == '/') {
                    int tmp = numStack.top();
                    numStack.pop();
                    numStack.push(tmp / num);
                }
                sign = s[i];
                num = 0;
            }
        }
        int ret = 0;
        while (!numStack.empty()) {
            ret += numStack.top();
            numStack.pop();
        }
        return ret;
    }
};
// @lc code=end
