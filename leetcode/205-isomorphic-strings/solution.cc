/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (50.02%)
 * Likes:    447
 * Dislikes: 0
 * Total Accepted:    137.8K
 * Total Submissions: 276.5K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings s and t are isomorphic if the characters in s can be replaced to
 * get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character, but a character may map to itself.
 *
 *
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s and t consist of any valid ascii character.
 *
 *
 */
#include <string>

using namespace std;
// 同构字符串，出现的每个字符都能映射到另一个字符串，且不改变顺序
// @lc code=start
class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        int mapping[128] = {};
        int mappingReverse[128] = {};
        for (int i = 0; i < s.size(); i++) {
            if (mapping[s[i]] == 0) {
                if (mappingReverse[t[i]] != 0)
                    return false;
                mapping[s[i]] = t[i];
                mappingReverse[t[i]] = s[i];

            } else {
                if (mapping[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    Solution s;
    s.isIsomorphic("badc", "babc");
    return 0;
}
