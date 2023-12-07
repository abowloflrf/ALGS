/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 *
 * https://leetcode-cn.com/problems/determine-if-two-strings-are-close/description/
 *
 * algorithms
 * Medium (46.57%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    38.7K
 * Total Submissions: 72.4K
 * Testcase Example:  '"abc"\n"bca"'
 *
 * Two strings are considered close if you can attain one from the other using
 * the following operations:
 *
 *
 * Operation 1: Swap any two existing characters.
 *
 *
 * For example, abcde -> aecdb
 *
 *
 * Operation 2: Transform every occurrence of one existing character into
 * another existing character, and do the same with the other
 * character.
 *
 * For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into
 * a's)
 *
 *
 *
 *
 * You can use the operations on either string as many times as necessary.
 *
 * Given two strings, word1 and word2, return true if word1 and word2 are
 * close, and false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "abc", word2 = "bca"
 * Output: true
 * Explanation: You can attain word2 from word1 in 2 operations.
 * Apply Operation 1: "abc" -> "acb"
 * Apply Operation 1: "acb" -> "bca"
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "a", word2 = "aa"
 * Output: false
 * Explanation: It is impossible to attain word2 from word1, or vice versa, in
 * any number of operations.
 *
 *
 * Example 3:
 *
 *
 * Input: word1 = "cabbba", word2 = "abbccc"
 * Output: true
 * Explanation: You can attain word2 from word1 in 3 operations.
 * Apply Operation 1: "cabbba" -> "caabbb"
 * Apply Operation 2: "caabbb" -> "baaccc"
 * Apply Operation 2: "baaccc" -> "abbccc"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word1.length, word2.length <= 10^5
 * word1 and word2 contain only lowercase English letters.
 *
 *
 */

#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;

        vector<int> charmap1(26), charmap2(26);
        for (char c : word1) {
            charmap1[c - 'a']++;
        }
        for (char c : word2) {
            charmap2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if ((charmap1[i] == 0 && charmap2[i] != 0) || (charmap2[i] == 0 && charmap1[i] != 0)) {
                return false;
            }
        }
        sort(charmap1.begin(), charmap1.end());
        sort(charmap2.begin(), charmap2.end());
        return charmap1 == charmap2;
    }
};
// @lc code=end
