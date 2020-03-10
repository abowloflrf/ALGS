/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (60.96%)
 * Likes:    1710
 * Dislikes: 52
 * Total Accepted:    97.9K
 * Total Submissions: 160.4K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 *
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 *
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 *
 *
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 *
 */

#include <stack>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &T) {
        vector<int> res(T.size(), 0);
        stack<int> s; // stack中保存的是index
        for (int i = 0; i < T.size(); i++) {
            while (!s.empty() && T[i] > T[s.top()]) {
                int index = s.top();
                s.pop();
                res[index] = i - index;
            }
            s.push(i);
        }
        return res;
    }
};
// @lc code=end
