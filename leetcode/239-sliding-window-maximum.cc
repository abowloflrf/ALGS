/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (39.72%)
 * Likes:    2663
 * Dislikes: 159
 * Total Accepted:    229K
 * Total Submissions: 559.5K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 *
 * Example:
 *
 *
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 *
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
 * array.
 *
 * Follow up:
 * Could you solve it in linear time?
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (nums.empty())
            return {};
        deque<int> q; // q存nums的下标
        // 先开始第一个窗口
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
        }
        vector<int> res{nums[q.front()]};
        // 开始向后滑动
        for (int i = k; i < nums.size(); i++) {
            // 入队
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            // 若窗口内数字都是倒序的则入队时没有在while内执行任何出队操作
            if (q.front() == i - k)
                q.pop_front();
            // 保存当前最大值
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> in = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> res = s.maxSlidingWindow(in, 3);
    return 0;
}