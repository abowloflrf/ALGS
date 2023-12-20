/*
 * @lc app=leetcode.cn id=1544 lang=cpp
 *
 * [1544] Make The String Great
 *
 * https://leetcode.cn/problems/make-the-string-great/description/
 *
 * algorithms
 * Easy (55.48%)
 * Likes:    46
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 43.5K
 * Testcase Example:  '"leEeetcode"'
 *
 * Given a string s of lower and upper case English letters.
 *
 * A good string is a string which doesn't have two adjacent characters s[i]
 * and s[i + 1] where:
 *
 *
 * 0 <= i <= s.length - 2
 * s[i] is a lower-case letter and s[i + 1] is the same letter but in
 * upper-case or vice-versa.
 *
 *
 * To make the string good, you can choose two adjacent characters that make
 * the string bad and remove them. You can keep doing this until the string
 * becomes good.
 *
 * Return the string after making it good. The answer is guaranteed to be
 * unique under the given constraints.
 *
 * Notice that an empty string is also good.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leEeetcode"
 * Output: "leetcode"
 * Explanation: In the first step, either you choose i = 1 or i = 2, both will
 * result "leEeetcode" to be reduced to "leetcode".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abBAcC"
 * Output: ""
 * Explanation: We have many possible scenarios, and all lead to the same
 * answer. For example:
 * "abBAcC" --> "aAcC" --> "cC" --> ""
 * "abBAcC" --> "abBA" --> "aA" --> ""
 *
 *
 * Example 3:
 *
 *
 * Input: s = "s"
 * Output: "s"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s contains only lower and upper case English letters.
 *
 *
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
  public:
    string makeGood(string s) {
        string ans;
        int i = 0;
        while (i < s.length() - 1) {
            if (s[i + 1] < s[i] && tolower(s[i + 1]) == s[i]) {
                i++;
                continue;
            }
            if (s[i + 1] > s[i] && toupper(s[i + 1]) == s[i]) {
                i++;
                continue;
            }
        }

        for (int i = 0; i < s.length() - 1; i++) {

            if (s[i + 1] < s[i] && tolower(s[i + 1]) == s[i]) {
                i++;
                continue;
            }
            if (s[i + 1] > s[i] && toupper(s[i + 1]) == s[i]) {
                i++;
                continue;
            }
            ans += s[i];
            if (i == s.length() - 2) {
                ans += s[i + 1];
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    s.makeGood("leEeetcode");
    return 0;
}
