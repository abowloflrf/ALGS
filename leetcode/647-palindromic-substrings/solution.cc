/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (65.67%)
 * Likes:    688
 * Dislikes: 0
 * Total Accepted:    124.5K
 * Total Submissions: 189.6K
 * Testcase Example:  '"abc"'
 *
 * Given a string s, return the number of palindromic substrings in it.
 *
 * A string is a palindrome when it reads the same backward as forward.
 *
 * A substring is a contiguous sequence of characters within the string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consists of lowercase English letters.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += countWithMiddleIndex(s, i, i);
            ans += countWithMiddleIndex(s, i, i + 1);
        }
        return ans;
    }

  private:
    int countWithMiddleIndex(string &s, int idx1, int idx2) {
        if (idx2 >= s.size())
            return 0;
        if (s[idx1] != s[idx2])
            return 0;
        int cnt = 0;
        while (idx1 >= 0 && idx2 < s.size() && s[idx1] == s[idx2]) {
            cnt++;
            idx1--;
            idx2++;
        }
        return cnt;
    }
};
// @lc code=end
