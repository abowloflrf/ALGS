/*
 * @lc app=leetcode.cn id=240 lang=golang
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (46.39%)
 * Likes:    651
 * Dislikes: 0
 * Total Accepted:    139.2K
 * Total Submissions: 300.2K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * Write an efficient algorithm that searches for a target value in an m x n
 * integer matrix. The matrix has the following properties:
 *
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 5
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 20
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -10^9 <= matix[i][j] <= 10^9
 * All the integers in each row are sorted in ascending order.
 * All the integers in each column are sorted in ascending order.
 * -10^9 <= target <= 10^9
 *
 *
*/

package leetcode_240

// @lc code=start
func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	x := 0
	y := len(matrix[0]) - 1
	for {
		if x <= len(matrix)-1 && y >= 0 {
			if matrix[x][y] == target {
				return true
			} else if matrix[x][y] > target {
				y--
			} else if matrix[x][y] < target {
				x++
			}
		} else {
			break
		}
	}
	return false
}

// @lc code=end
