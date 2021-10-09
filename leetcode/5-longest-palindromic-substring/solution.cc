/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (34.87%)
 * Likes:    3896
 * Dislikes: 0
 * Total Accepted:    662.9K
 * Total Submissions: 1.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: "bb"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a"
 * Output: "a"
 *
 *
 * Example 4:
 *
 *
 * Input: s = "ac"
 * Output: "a"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 *
 *
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
  public:
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            findWithMiddleIndex(s, i, i);
            findWithMiddleIndex(s, i, i + 1);
        }
        return s.substr(index, maxLen);
    }

  private:
    int index;  // 左边起点
    int maxLen; // 当前最大长度

    // 不论长度奇偶，idx1 idx2 为中心，若奇数则 idx1=idx2
    void findWithMiddleIndex(string &s, int idx1, int idx2) {
        if (idx2 >= s.size())
            return;
        if (s[idx1] != s[idx2])
            return;
        int currLen = idx2 - idx1 + 1;
        int left = idx1, right = idx2;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            currLen = right - left + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
                index = left;
            }
            left--;
            right++;
        }
    }
};
// @lc code=end
