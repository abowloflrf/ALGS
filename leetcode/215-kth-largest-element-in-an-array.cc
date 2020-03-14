/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (50.45%)
 * Likes:    3049
 * Dislikes: 215
 * Total Accepted:    538.3K
 * Total Submissions: 1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 */
#include <queue>
#include <set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int n : nums) {
            q.push(n);
            if (q.size() > k)
                q.pop();
        }
    
        return q.top();
    }
};
// @lc code=end

int main() {
    priority_queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(1);
    int a = q.top();
    q.pop();
    int b = q.top();

    return 0;
}
