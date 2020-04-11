/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.12%)
 * Likes:    5928
 * Dislikes: 486
 * Total Accepted:    850.8K
 * Total Submissions: 2.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    string longestPalindrome(string s) {
        int res = 0;
        int pos = 0;
        for (int i = 0; i < s.size(); i++) {
            int r1 = findPalindrome1(s, i);
            if (r1 > res) {
                res = r1;
                pos = i - (r1 - 1) / 2;
            }
            int r2 = findPalindrome2(s, i, i + 1);
            if (r2 > res) {
                res = r2;
                pos = i - (r2 - 2) / 2;
            }
        }
        return s.substr(pos, res);
    }

  private:
    // 以mid为中心的最长回文串，长度为奇数
    int findPalindrome1(string &s, int mid) {
        int left = mid - 1, right = mid + 1;
        int r = 1;

        while (left >= 0 && right < s.size()) {
            if (s[left--] == s[right++]) {
                r += 2;
            } else
                break;
        }
        return r;
    }
    // 以mid1 mid2为中心的最长回文串，长度为偶数
    int findPalindrome2(string &s, int mid1, int mid2) {
        if (mid2 >= s.size())
            return 0;
        int r = 0;
        while (mid1 >= 0 && mid2 < s.size()) {
            if (s[mid1--] == s[mid2++]) {
                r += 2;
            } else
                break;
        }
        return r;
    }
};
// @lc code=end

int main() {
    Solution s;
    string r = s.longestPalindrome("babad");
    return 0;
}