/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (39.65%)
 * Likes:    1217
 * Dislikes: 107
 * Total Accepted:    70.1K
 * Total Submissions: 173K
 * Testcase Example:  '"aaabb"\n3'
 *
 *
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than
 * k times.
 *
 *
 * Example 1:
 *
 * Input:
 * s = "aaabb", k = 3
 *
 * Output:
 * 3
 *
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s = "ababbc", k = 2
 *
 * Output:
 * 5
 *
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
 * repeated 3 times.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    int longestSubstring(string s, int k) {
        int charMap[128];
        for (int i = 0; i < 128; i++) {
            charMap[i] = 0;
        }
        for (char c : s)
            charMap[c]++;
        int ans = 0;

        int idx = 0;
        while (idx < s.size()) {
            while (idx < s.size() && charMap[s[idx]] < k)
                idx++;
            int len = 0;
            while (idx < s.size() && charMap[s[idx]] >= k) {
                idx++;
                len++;
            }
            // 遍历判断一下
            int tmpMap[128];
            for (int i = 0; i < 128; i++) {
                tmpMap[i] = 0;
            }
            bool flag = false;
            for (int i = 0; i < len; i++) {
                tmpMap[s[idx - 1 - i]]++;
            }
            for (int i = 0; i < 128; i++) {
                if (tmpMap[i] > 0 && tmpMap[i] < k) {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                ans = max(ans, len);
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    int r = s.longestSubstring("aaabb", 3);
    return 0;
}