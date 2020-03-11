/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (53.94%)
 * Likes:    1176
 * Dislikes: 129
 * Total Accepted:    487.6K
 * Total Submissions: 882K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 *
 * Example 1:
 *
 *
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool isAnagram(string s, string t) {
        int M[128] = {0};
        for (char c : s)
            M[c]++;
        for (char c : t)
            M[c]--;
        for (int i = 0; i < 128; i++)
            if (M[i] != 0)
                return false;
        return true;
    }
};
// @lc code=end
