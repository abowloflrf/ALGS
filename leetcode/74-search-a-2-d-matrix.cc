/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (35.42%)
 * Likes:    1365
 * Dislikes: 142
 * Total Accepted:    289.3K
 * Total Submissions: 805.7K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 *
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int height = matrix.size();
        if (height == 0)
            return false;
        int width = matrix[0].size();
        if (width == 0)
            return false;
        int start = 0, end = width * height - 1;
        int mid, curr;
        while (start <= end) {
            mid = start + (end - start) / 2;
            curr = matrix[mid / width][mid % height];
            if (curr == target)
                return true;
            if (curr > target) {
                start = mid + 1;
            } else if (curr < target) {
                end = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end
