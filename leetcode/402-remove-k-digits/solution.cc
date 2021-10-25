/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] Remove K Digits
 *
 * https://leetcode-cn.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (32.71%)
 * Likes:    669
 * Dislikes: 0
 * Total Accepted:    82.4K
 * Total Submissions: 251.9K
 * Testcase Example:  '"1432219"\n3'
 *
 * Given string num representing a non-negative integer num, and an integer k,
 * return the smallest possible integer after removing k digits from num.
 *
 *
 * Example 1:
 *
 *
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
 * which is the smallest.
 *
 *
 * Example 2:
 *
 *
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the
 * output must not contain leading zeroes.
 *
 *
 * Example 3:
 *
 *
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with
 * nothing which is 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= num.length <= 10^5
 * num consists of only digits.
 * num does not have any leading zeros except for the zero itself.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    string removeKdigits(string num, int k) {
        while (k--) {
            if (num.size() <= 1) {
                return "0";
            }
            int target = 0;
            for (int i = 0; i < num.size(); i++) {
                if (i == num.size() - 1 || num[i] > num[i + 1]) {
                    target = i;
                    break;
                }
            }
            num.erase(num.begin() + target);
            // 若可能，删除前导0
            while (!num.empty() && num[0] == '0') {
                num.erase(num.begin());
            }
        }
        if (num.empty())
            return "0";
        return num;
    }
};
// @lc code=end
