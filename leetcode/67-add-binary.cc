/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (44.98%)
 * Likes:    1900
 * Dislikes: 281
 * Total Accepted:    477.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 *
 * Constraints:
 *
 *
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 *
 *
 */

#include <stack>
#include <string>
using namespace std;

// @lc code=start
class Solution {
  public:
    string addBinary(string a, string b) {
        stack<char> res;
        int flag = 0;
        int sizeA = a.size();
        int sizeB = b.size();
        for (int i = 0; i <= sizeA && i <= sizeB; i++) {
            if (a[sizeA - i] == '1' && b[sizeB - i] == '1') {
                if (!flag) {
                    res.push('0');
                    flag = 1;
                } else
                    res.push('1');
            }
            if (a[sizeA - i] == '1' || b[sizeB - i] == '1') {
                if (!flag) {
                    res.push('1');
                } else {
                    res.push('0');
                }
            }
            if (flag)
                res.push('1');
            else
                res.push('0');
        }
    }
};
// @lc code=end
