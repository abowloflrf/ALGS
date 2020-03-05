/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (34.01%)
 * Likes:    925
 * Dislikes: 2532
 * Total Accepted:    496.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 *
 * Example 1:
 *
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "race a car"
 * Output: false
 *
 *
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool isPalindrome(string s) {
        for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
            while (!isalnum(s[left]) && left < right)
                left++;
            while (!isalnum(s[right]) && left < right)
                right--;
            if (toupper(s[left]) != toupper(s[right]))
                return false;
        }
        return true;
    }
};
// @lc code=end
