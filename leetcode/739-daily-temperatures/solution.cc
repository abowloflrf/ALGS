/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (67.98%)
 * Likes:    891
 * Dislikes: 0
 * Total Accepted:    212.6K
 * Total Submissions: 312.7K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 *
 *
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 *
 *
 * Constraints:
 *
 *
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 *
 *
 */
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        // 单调递减栈，存放 index
        stack<int> s;
        vector<int> ans(temperatures.size(), 0);
        // 一次遍历
        for (int i = 0; i < temperatures.size(); i++) {
            // 若比栈顶大，从栈顶依次 pop 输出结果
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            // 若栈为空或比栈顶小，直接 push
            if (s.empty() || temperatures[i] <= temperatures[s.top()]) {
                s.push(i);
            }
        }
        return ans;
    }
};
// @lc code=end
