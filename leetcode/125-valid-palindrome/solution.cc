/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (47.28%)
 * Likes:    392
 * Dislikes: 0
 * Total Accepted:    246.3K
 * Total Submissions: 520.6K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string s, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 *
 *
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool isPalindrome(string s) {
        for (int start = 0, end = s.size() - 1; start < end; start++, end--) {
            while (!isalnum(s[start]) && end > start)
                start++;
            while (!isalnum(s[end]) && end > start)
                end--;
            if (tolower(s[start]) != tolower(s[end]))
                return false;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    auto a1 = s.isPalindrome("A mn, a plan, a canal: Panama");
    auto a2 = s.isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}
