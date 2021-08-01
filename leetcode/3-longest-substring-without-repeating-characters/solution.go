/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (37.63%)
 * Likes:    5843
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 3M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *
 *
 * Example 4:
 *
 *
 * Input: s = ""
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */
package leetcode_3

// @lc code=start
func lengthOfLongestSubstring(s string) int {
	// 保存字符出现的位置上一次出现的位置
	positions := [128]int{}
	for i := range positions {
		positions[i] = -1
	}
	max := 0
	cur := 0
	// 遍历时记住当前长度
	for i := range s {
		pos := positions[s[i]]
		// 从未出现过，或出现位置在当前窗户前面
		if pos == -1 || pos < i-cur {
			cur++
		} else {
			cur = i - pos
		}
		if cur > max {
			max = cur
		}
		positions[s[i]] = i
	}
	return max
}

// @lc code=end
