/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.02%)
 * Likes:    8308
 * Dislikes: 506
 * Total Accepted:    1.4M
 * Total Submissions: 4.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 *
 */

#include <string>
using namespace std;

/**
 * 例如字符串 abcabcaa
 * 从头开始判断abc，到第四个字符a时出现了重复的，这时需要从b开始计算
 * 因此在维护这个不重复字符串窗口时需要记录每个字符出现的位置
 **/

// @lc code=start
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        // 初始化位置数组，记录字母在最后一次出现的位置
        int pos[128];
        for (int i = 0; i < 128; i++) {
            pos[i] = -1;
        }
        int maxLen = 0;
        int currLen = 0;
        for (int i = 0; i < s.size(); i++) {
            int prevPos = pos[s[i]];
            // 新的字符未在窗口中出现过，或出现过但是在窗口前出现过，直接加一
            if (prevPos == -1 || prevPos < i - currLen) {
                currLen++;
            } else {
                // 出现过，则停止，
                maxLen = max(currLen, maxLen);
                // 重新从上次出现的位置后计算长度
                currLen = i - pos[s[i]];
            }
            // 记录当前字符的位置，不管之前有没有出现过，覆盖掉位置值
            pos[s[i]] = i;
        }
        if (currLen > maxLen)
            maxLen = currLen;
        return maxLen;
    }
};
// @lc code=end

int main() {
    Solution s;
    int r = s.lengthOfLongestSubstring("abba");
    return 0;
}