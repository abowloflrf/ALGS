/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] Next Greater Element II
 *
 * https://leetcode-cn.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (63.26%)
 * Likes:    468
 * Dislikes: 0
 * Total Accepted:    96.3K
 * Total Submissions: 152.2K
 * Testcase Example:  '[1,2,1]'
 *
 * Given a circular integer array nums (i.e., the next element of
 * nums[nums.length - 1] is nums[0]), return the next greater number for every
 * element in nums.
 *
 * The next greater number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, return -1 for this
 * number.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2;
 * The number 2 can't find next greater number.
 * The second 1's next greater number needs to search circularly, which is also
 * 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4,3]
 * Output: [2,3,4,-1,4]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> s;
        int size = nums.size();
        for (int i = 0; i < 2 * nums.size(); i++) {
            while (!s.empty() && nums[s.top()] < nums[i % size]) {
                ans[s.top()] = nums[i % size];
                s.pop();
            }
            s.push(i % size);
        }
        return ans;
    }
};
// @lc code=end
