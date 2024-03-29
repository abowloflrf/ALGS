/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode-cn.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (51.43%)
 * Likes:    492
 * Dislikes: 0
 * Total Accepted:    139.4K
 * Total Submissions: 271K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * Given two strings s and t, return true if s is a subsequence of t, or false
 * otherwise.
 *
 * A subsequence of a string is a new string that is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (i.e., "ace" is a
 * subsequence of "abcde" while "aec" is not).
 *
 *
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * s and t consist only of lowercase English letters.
 *
 *
 *
 * Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k
 * >= 10^9, and you want to check one by one to see if t has its subsequence.
 * In this scenario, how would you change your code?
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool isSubsequence(string s, string t) {
        // s 空字符串时也满足要求
        if (s.size() == 0) {
            return true;
        }
        int idx = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[idx]) {
                idx++;
                if (idx == s.size()) {
                    return true;
                }
                continue;
            }
        }
        return false;
    }
};
// @lc code=end
