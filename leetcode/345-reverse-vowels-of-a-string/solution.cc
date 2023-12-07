/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.cn/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (54.66%)
 * Likes:    340
 * Dislikes: 0
 * Total Accepted:    185.2K
 * Total Submissions: 338.8K
 * Testcase Example:  '"hello"'
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 *
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * lower and upper cases, more than once.
 *
 *
 * Example 1:
 * Input: s = "hello"
 * Output: "holle"
 * Example 2:
 * Input: s = "leetcode"
 * Output: "leotcede"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 *
 *
 */
#include <string>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
  public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            if (!isVowels(s[i])) {
                i++;
                continue;
            }
            if (!isVowels(s[j])) {
                j--;
                continue;
            }
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        return s;
    }
    bool isVowels(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' ||
               c == 'O' || c == 'U';
    }
};
// @lc code=end
