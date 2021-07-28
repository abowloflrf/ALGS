/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.55%)
 * Likes:    666
 * Dislikes: 2452
 * Total Accepted:    379.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word (last word means the last
 * appearing word if we loop from left to right) in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a maximal substring consisting of non-space
 * characters only.
 *
 * Example:
 *
 *
 * Input: "Hello World"
 * Output: 5
 *
 *
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool start = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (start)
                    break;
                continue;
            } else {
                len++;
                start = true;
            }
        }
        return len;
    }
};
// @lc code=end
