/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (42.13%)
 * Likes:    1279
 * Dislikes: 0
 * Total Accepted:    163.2K
 * Total Submissions: 387.4K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 *
 * The testcases will be generated such that the answer is unique.
 *
 * A substring is a contiguous sequence of characters within the string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 *
 *
 *
 * Constraints:
 *
 *
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 *
 *
 *
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 */
#include <string>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
  public:
    bool check(unordered_map<char, int> a, unordered_map<char, int> b) {
        for (auto t : b) {
            if (a[t.first] != t.second) {
                return false;
            }
        }
        return true;
    };

    string minWindow(string s, string t) {
        unordered_map<char, int> target, current;
        for (const char &c : t) {
            target[c]++;
        }
        int count = t.size();

        int minSize = INT_MAX;
        int currentSize = 0;
        for (int i = 0; i < s.size(); i++) {
            if (currentSize == 0) {
                while (target.find(s[i]) == target.end()) {
                    i++;
                }
                continue;
            }
            if (target[s[i]] > 0) {
                currentSize++;
                current[s[i]]++;
            }
            if (check(current, target)) {
                if (currentSize < minSize) {
                    minSize = currentSize;
                }
                currentSize = 0;
            }
        }
        return "";
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    s.minWindow("abcasdads", "abbccc");
    return 0;
}
