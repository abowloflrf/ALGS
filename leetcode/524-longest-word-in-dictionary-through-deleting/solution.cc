/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (47.38%)
 * Likes:    165
 * Dislikes: 0
 * Total Accepted:    40.2K
 * Total Submissions: 84.9K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * Given a string s and a string array dictionary, return the longest string in
 * the dictionary that can be formed by deleting some of the given string
 * characters. If there is more than one possible result, return the longest
 * word with the smallest lexicographical order. If there is no possible
 * result, return the empty string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * Output: "apple"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abpcplea", dictionary = ["a","b","c"]
 * Output: "a"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 1000
 * s and dictionary[i] consist of lowercase English letters.
 *
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    string findLongestWord(string s, vector<string> &dictionary) {
        string ans;
        for (string &d : dictionary) {
            if (match(s, d)) {
                if (d.size() > ans.size()) {
                    ans = d;
                } else if (d.size() == ans.size()) {
                    if (d < ans)
                        ans = d;
                }
            }
        }
        return ans;
    }

  private:
    bool match(string &s, string &t) {
        int idx = 0;
        for (char c : t) {
            bool matched = false;
            while (idx < s.size()) {
                if (s[idx++] == c) {
                    matched = true;
                    break;
                }
            }
            if (!matched)
                return false;
        }
        return true;
    }
};
// @lc code=end
