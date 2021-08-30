/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (37.84%)
 * Likes:    6005
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 3.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *
 *
 * Example 4:
 *
 *
 * Input: s = ""
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int charPos[128];
        for (int i = 0; i < 128; i++) {
            charPos[i] = -1;
        }
        int maxLen = 0;
        int curLen = 0;
        for (int i = 0; i < s.size(); i++) {
            int pos = charPos[s[i]];
            // 未找到或在窗口之前
            if (pos == -1 || pos < i - curLen) {
                curLen++;
            } else {
                // 找到上次出现的位置，从上次位置重新resize
                curLen = i - pos;
            }
            if (curLen > maxLen)
                maxLen = curLen;
            // 判断完之后再记录当前字符位置
            charPos[s[i]] = i;
        }
        return maxLen;
    }
};
// @lc code=end
