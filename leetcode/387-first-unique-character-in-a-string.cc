/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.83%)
 * Likes:    1526
 * Dislikes: 100
 * Total Accepted:    400.6K
 * Total Submissions: 777.1K
 * Testcase Example:  '"leetcode"'
 *
 *
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 *
 *
 *
 *
 * Note: You may assume the string contain only lowercase letters.
 *
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
  public:
    int firstUniqChar(string s) {
        // TIPS: 使用 int[128] 而不是 unordered_map 会更快
        int M[128] = {0};
        for (char c : s) {
            M[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (M[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
