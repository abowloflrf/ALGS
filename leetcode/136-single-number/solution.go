/*
 * @lc app=leetcode.cn id=136 lang=golang
 *
 * [136] Single Number
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (71.60%)
 * Likes:    1902
 * Dislikes: 0
 * Total Accepted:    424.7K
 * Total Submissions: 593.1K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers nums, every element appears twice except
 * for one. Find that single one.
 *
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 *
 *
 * Example 1:
 * Input: nums = [2,2,1]
 * Output: 1
 * Example 2:
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 * Example 3:
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * Each element in the array appears twice except for one element which appears
 * only once.
 *
 *
 */

package leetcode_136

func singleNumberWithMap(nums []int) int {
	m := make(map[int]struct{})
	exists := make(map[int]struct{})
	for _, i := range nums {
		if _, ok := exists[i]; ok {
			continue
		} else if _, ok := m[i]; ok {
			exists[i] = struct{}{}
			delete(m, i)
		} else {
			m[i] = struct{}{}
		}
	}
	for k := range m {
		return k
	}
	return 0
}

// @lc code=start
func singleNumber(nums []int) int {
	var r int
	for _, i := range nums {
		r ^= i
	}
	return r
}

// @lc code=end
