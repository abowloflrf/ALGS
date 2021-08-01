/*
 * @lc app=leetcode.cn id=4 lang=golang
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (40.53%)
 * Likes:    4301
 * Dislikes: 0
 * Total Accepted:    463.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 *
 * The overall run time complexity should be O(log (m+n)).
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 *
 *
 * Example 3:
 *
 *
 * Input: nums1 = [0,0], nums2 = [0,0]
 * Output: 0.00000
 *
 *
 * Example 4:
 *
 *
 * Input: nums1 = [], nums2 = [1]
 * Output: 1.00000
 *
 *
 * Example 5:
 *
 *
 * Input: nums1 = [2], nums2 = []
 * Output: 2.00000
 *
 *
 *
 * Constraints:
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */
package leetcode_4

// @lc code=start
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	total := len(nums1) + len(nums2)
	idx1, idx2 := 0, 0
	middle, preMiddle := 0, 0
	for (idx1 + idx2) <= total/2 {
		preMiddle = middle
		if idx1 < len(nums1) && idx2 < len(nums2) {
			if nums1[idx1] < nums2[idx2] {
				middle = nums1[idx1]
				idx1++
			} else {
				middle = nums2[idx2]
				idx2++
			}
		} else if idx1 < len(nums1) {
			middle = nums1[idx1]
			idx1++
		} else {
			middle = nums2[idx2]
			idx2++
		}
	}
	if total%2 == 0 {
		return (float64(middle) + float64(preMiddle)) / 2
	}
	return float64(middle)
}

// @lc code=end
