/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (33.12%)
 * Likes:    1332
 * Dislikes: 1724
 * Total Accepted:    595.1K
 * Total Submissions: 1.8M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 *
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (compare(haystack, i, needle))
                return i;
        }
        return -1;
    }

  private:
    bool compare(string &haystack, int idx, string &needle) {
        if (idx + needle.size() > haystack.size())
            return false;
        for (int i = 0; i < needle.size(); i++) {
            if (haystack[i + idx] != needle[i])
                return false;
        }
        return true;
    }
};
// @lc code=end
