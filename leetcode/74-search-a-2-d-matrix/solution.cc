/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (45.08%)
 * Likes:    446
 * Dislikes: 0
 * Total Accepted:    143.2K
 * Total Submissions: 317.7K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
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
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 *
 *
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // 两次二分查找
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        vector<int> col;
        for (auto c : matrix) {
            col.push_back(c[0]);
        }
        auto pos1 = bs(col, 0, col.size() - 1, target);
        if (pos1 == -1) {
            return false;
        }
        auto pos2 = bs(matrix[pos1], 0, matrix[pos1].size() - 1, target);
        if (pos2 == -1 || matrix[pos1][pos2] != target) {
            return false;
        }
        return true;
    }
    // binary search 返回 idx
    int bs(const vector<int> &nums, const int &start, const int &end, const int &target) {
        if (target > nums.back()) {
            return nums.size() - 1;
        } else if (target < nums.front()) {
            return -1;
        }

        if (start == end) {
            return start;
        }
        if (end - start == 1) {
            if (nums[end] == target) {
                return end;
            } else {
                return start;
            }
        }
        int mid = (end + start) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return bs(nums, start, mid, target);
        } else {
            return bs(nums, mid, end, target);
        }
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    auto b = s.searchMatrix(matrix, 5);
    return 0;
}
