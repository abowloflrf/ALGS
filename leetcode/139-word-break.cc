/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (37.01%)
 * Likes:    3494
 * Dislikes: 191
 * Total Accepted:    471.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 *
 * Note:
 *
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 *
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        memo = vector<int>(s.size(), -1);
        return helper(s, wordDict, 0);
    }

  private:
    bool helper(string &s, vector<string> &wordDict, int index) {
        if (index == s.size())
            return true;
        if (memo[index] != -1)
            return memo[index];
        for (string word : wordDict) {
            if (hasPrefix(s, word, index) && helper(s, wordDict, index + word.size())) {
                memo[index] = true;
                return true;
            }
        }
        memo[index] = false;
        return false;
    }
    bool hasPrefix(string &s, string &prefix, int index) {
        if (prefix.size() + index > s.size())
            return false;
        for (char c : prefix) {
            if (s[index++] != c)
                return false;
        }
        return true;
    }
    vector<int> memo;
};
// @lc code=end

int main() {
    Solution s;

    vector<string> dict = {"a",      "aa",      "aaa",      "aaaa",      "aaaaa",
                           "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    bool r = s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
                         dict);
    return 0;
}