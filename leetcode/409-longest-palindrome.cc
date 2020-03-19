/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (48.90%)
 * Likes:    782
 * Dislikes: 75
 * Total Accepted:    128K
 * Total Submissions: 257.8K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 *
 * Note:
 * Assume the length of given string will not exceed 1,010.
 *
 *
 * Example:
 *
 * Input:
 * "abccccdd"
 *
 * Output:
 * 7
 *
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 *
 *
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
  public:

    int longestPalindrome(string s) {
        bool chars[128] = {false};
        for (char c : s) {
            chars[c] = !chars[c];
        }
        int count = 0;
        for (int i = 0; i < 128; i++) {
            if (chars[i])
                count++;
        }
        if (count == 0)
            return s.size();
        return s.size() - count + 1;
    }
};
// @lc code=en

// int longestPalindrome(string s) {
//     unordered_set<char> S;
//     for (char c : s) {
//         if (S.find(c) == S.end()) {
//             S.insert(c);
//         } else {
//             S.erase(c);
//         }
//     }
//     if (S.empty())
//         return s.size();
//     return s.size() - S.size() + 1;
// }