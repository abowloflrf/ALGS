/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 *
 * https://leetcode-cn.com/problems/merge-strings-alternately/description/
 *
 * algorithms
 * Easy (76.24%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    96.4K
 * Total Submissions: 128.9K
 * Testcase Example:  '"abc"\n"pqr"'
 *
 * You are given two strings word1 and word2. Merge the strings by adding
 * letters in alternating order, starting with word1. If a string is longer
 * than the other, append the additional letters onto the end of the merged
 * string.
 *
 * Return the merged string.
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "abc", word2 = "pqr"
 * Output: "apbqcr"
 * Explanation: The merged string will be merged as so:
 * word1:  a   b   c
 * word2:    p   q   r
 * merged: a p b q c r
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "ab", word2 = "pqrs"
 * Output: "apbqrs"
 * Explanation: Notice that as word2 is longer, "rs" is appended to the end.
 * word1:  a   b
 * word2:    p   q   r   s
 * merged: a p b q   r   s
 *
 *
 * Example 3:
 *
 *
 * Input: word1 = "abcd", word2 = "pq"
 * Output: "apbqcd"
 * Explanation: Notice that as word1 is longer, "cd" is appended to the end.
 * word1:  a   b   c   d
 * word2:    p   q
 * merged: a p b q c   d
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word1.length, word2.length <= 100
 * word1 and word2 consist of lowercase English letters.
 *
 */

#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int len = word1.size();
        if (word1.size() < word2.size()) {
            len = word2.size();
        }
        for (int i = 0; i < len; i++) {
            if (i < word1.size()) {
                res += word1[i];
            }
            if (i < word2.size()) {
                res += word2[i];
            }
        }
        return res;
    }
};
// @lc code=end
