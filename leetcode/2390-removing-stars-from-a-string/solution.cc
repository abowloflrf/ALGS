/*
 * @lc app=leetcode.cn id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 *
 * https://leetcode.cn/problems/removing-stars-from-a-string/description/
 *
 * algorithms
 * Medium (71.29%)
 * Likes:    34
 * Dislikes: 0
 * Total Accepted:    25K
 * Total Submissions: 35.1K
 * Testcase Example:  '"leet**cod*e"'
 *
 * You are given a string s, which contains stars *.
 *
 * In one operation, you can:
 *
 *
 * Choose a star in s.
 * Remove the closest non-star character to its left, as well as remove the
 * star itself.
 *
 *
 * Return the string after all stars have been removed.
 *
 * Note:
 *
 *
 * The input will be generated such that the operation is always possible.
 * It can be shown that the resulting string will always be unique.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leet**cod*e"
 * Output: "lecoe"
 * Explanation: Performing the removals from left to right:
 * - The closest character to the 1^st star is 't' in "leet**cod*e". s becomes
 * "lee*cod*e".
 * - The closest character to the 2^nd star is 'e' in "lee*cod*e". s becomes
 * "lecod*e".
 * - The closest character to the 3^rd star is 'd' in "lecod*e". s becomes
 * "lecoe".
 * There are no more stars, so we return "lecoe".
 *
 * Example 2:
 *
 *
 * Input: s = "erase*****"
 * Output: ""
 * Explanation: The entire string is removed, so we return an empty string.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters and stars *.
 * The operation above can be performed on s.
 *
 *
 */
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    string removeStars(string s) {
        stack<char> stck;
        for (const auto &c : s) {
            if (c == '*') {
                if (!stck.empty()) {
                    stck.pop();
                }
            } else {
                stck.push(c);
            }
        }

        int len = stck.size();
        string ans(len, ' ');
        for (int i = 0; i < len; i++) {
            ans[len - 1 - i] = stck.top();
            stck.pop();
        }
        return ans;
    }
};
// @lc code=end

// 第二种解法，快慢指针原地替换，空间 O(1)
class Solution2 {
  public:
    string removeStars(string s) {
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            if (s[right] == '*') {
                if (left > 0)
                    left--;
                right++;
            } else {
                // 如果前方不是 * ，字符直接移动到后面
                s[left] = s[right];
                left++;
                right++;
            }
        }
        //  最后 left 就是最终的长度
        s.resize(left);
        return s;
    }
};