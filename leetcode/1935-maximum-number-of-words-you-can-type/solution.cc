/*
 * @lc app=leetcode.cn id=1935 lang=cpp
 *
 * [1935] Maximum Number of Words You Can Type
 *
 * https://leetcode-cn.com/problems/maximum-number-of-words-you-can-type/description/
 *
 * algorithms
 * Easy (74.49%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 8K
 * Testcase Example:  '"hello world"\n"ad"'
 *
 * There is a malfunctioning keyboard where some letter keys do not work. All
 * other keys on the keyboard work properly.
 *
 * Given a string text of words separated by a single space (no leading or
 * trailing spaces) and a string brokenLetters of all distinct letter keys that
 * are broken, return the number of words in text you can fully type using this
 * keyboard.
 *
 *
 * Example 1:
 *
 *
 * Input: text = "hello world", brokenLetters = "ad"
 * Output: 1
 * Explanation: We cannot type "world" because the 'd' key is broken.
 *
 *
 * Example 2:
 *
 *
 * Input: text = "leet code", brokenLetters = "lt"
 * Output: 1
 * Explanation: We cannot type "leet" because the 'l' and 't' keys are
 * broken.
 *
 *
 * Example 3:
 *
 *
 * Input: text = "leet code", brokenLetters = "e"
 * Output: 0
 * Explanation: We cannot type either word because the 'e' key is broken.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= text.length <= 10^4
 * 0 <= brokenLetters.length <= 26
 * text consists of words separated by a single space without any leading or
 * trailing spaces.
 * Each word only consists of lowercase English letters.
 * brokenLetters consists of distinct lowercase English letters.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    int canBeTypedWords(string text, string brokenLetters) {
        if (text.size() == 0)
            return 0;

        int bls[128];
        for (int i = 0; i < 128; i++) {
            bls[i] = 0;
        }
        for (const char &c : brokenLetters) {
            bls[c]++;
        }

        int res = 0;
        bool cantype = true;
        for (const char &c : text) {
            if (!cantype) {
                if (c == ' ') {
                    cantype = true;
                }
                continue;
            }
            if (cantype && c == ' ') {
                res++;
                continue;
            }
            if (bls[c] > 0) {
                cantype = false;
            }
        }
        if (cantype) {
            res++;
        }
        return res;
    }
};
// @lc code=end
