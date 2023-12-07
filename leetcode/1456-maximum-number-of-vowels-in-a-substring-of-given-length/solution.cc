/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 *
 * https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
 *
 * algorithms
 * Medium (56.24%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    41.2K
 * Total Submissions: 73.3K
 * Testcase Example:  '"abciiidef"\n3'
 *
 * Given a string s and an integer k, return the maximum number of vowel
 * letters in any substring of s with length k.
 *
 * Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abciiidef", k = 3
 * Output: 3
 * Explanation: The substring "iii" contains 3 vowel letters.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aeiou", k = 2
 * Output: 2
 * Explanation: Any substring of length 2 contains 2 vowels.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "leetcode", k = 3
 * Output: 2
 * Explanation: "lee", "eet" and "ode" contain 2 vowels.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * 1 <= k <= s.length
 *
 *
 */

#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    int maxVowels(string s, int k) {
        int count = 0;
        int current = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                current++;
            }
        }
        count = current;
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i])) {
                current++;
            }
            if (isVowel(s[i - k])) {
                current--;
            }
            count = max(count, current);
        }
        return count;
    }
    bool isVowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    string input = "abciiidef";
    s.maxVowels(input, 3);
    return 0;
}
