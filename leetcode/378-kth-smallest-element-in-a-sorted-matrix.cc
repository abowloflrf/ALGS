/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (51.10%)
 * Likes:    1842
 * Dislikes: 109
 * Total Accepted:    157.9K
 * Total Submissions: 301.2K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 *
 *
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 *
 *
 * Example:
 *
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 *
 * return 13.
 *
 *
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */
#include <queue>
#include <vector>
using namespace std;

// @lc code=start
// 二分
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int lo = matrix[0][0];
        int hi = matrix.back().back();
        
        // 直到大与小相遇到目标k
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            // 确定矩阵中有多少个数<=mid
            int count = countNotGreaterThanN(matrix, mid);
            // 范围二分
            if (count < k)
                // 第k个数在右半部分 且不包含mid
                lo = mid + 1;
            else
                // 第k个数在左半部分 可能包含mid
                hi = mid;
        }
        return lo;
    }
    int countNotGreaterThanN(vector<vector<int>> &matrix, int target) {
        int n = matrix.size(), i = n - 1, j = 0, res = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                res += i + 1;
                ++j;
            } else {
                --i;
            }
        }
        return res;
    }
};
// @lc code=end

// 使用优先队列 O(n^2LogK)
class Solution2 {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        priority_queue<int> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                q.push(matrix[i][j]);
                if (q.size() > k)
                    q.pop();
            }
        return q.top();
    }
};