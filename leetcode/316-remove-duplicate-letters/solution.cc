/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 *
 * https://leetcode-cn.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (47.65%)
 * Likes:    604
 * Dislikes: 0
 * Total Accepted:    68.8K
 * Total Submissions: 144.5K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string s, remove duplicate letters so that every letter appears once
 * and only once. You must make sure your result is the smallest in
 * lexicographical order among all possible results.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "bcabc"
 * Output: "abc"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbacdcbc"
 * Output: "acdb"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of lowercase English letters.
 *
 *
 *
 * Note: This question is the same as 1081:
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 *
 */
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    string removeDuplicateLetters(string s) {
        // 统计词频
        int m[128];
        memset(m, 0, sizeof(m));
        for (char c : s) {
            m[c]++;
        }
        // 再次遍历找到要移除的字符
        // 对于每个要留的字符，需要使得留下的这个字符让整个字符串字典序列最小
        // 找到第一个 s[i]<s[i+1]
        // 若均 s[i]>=s[i+1] 去掉最后一个
        stack<char> stk;
        for (char c : s) {
            
            m[c]--;
        }
    }
};
// @lc code=end
