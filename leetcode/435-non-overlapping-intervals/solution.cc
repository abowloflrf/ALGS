/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * https://leetcode-cn.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (50.70%)
 * Likes:    522
 * Dislikes: 0
 * Total Accepted:    99.7K
 * Total Submissions: 196.7K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove to make the rest
 * of the intervals non-overlapping.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of the intervals are
 * non-overlapping.
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of the intervals
 * non-overlapping.
 *
 *
 * Example 3:
 *
 *
 * Input: intervals = [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
static bool comp(const vector<int> &a, const vector<int> &b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        // 按开头排序
        sort(intervals.begin(), intervals.end(), comp);
        // 贪心，若重叠，保留结尾小的
        int prev = 0;
        int ans = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[prev][1] > intervals[i][0]) {
                // 有重叠
                ans++;
                if (intervals[i][1] < intervals[prev][1]) {
                    prev = i;
                }
                continue;
            }
            prev = i;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> data = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    s.eraseOverlapIntervals(data);
    return 0;
}
