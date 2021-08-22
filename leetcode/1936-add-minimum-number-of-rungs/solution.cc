/*
 * @lc app=leetcode.cn id=1936 lang=cpp
 *
 * [1936] Add Minimum Number of Rungs
 *
 * https://leetcode-cn.com/problems/add-minimum-number-of-rungs/description/
 *
 * algorithms
 * Medium (44.91%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 11.8K
 * Testcase Example:  '[1,3,5,10]\n2'
 *
 * You are given a strictly increasing integer array rungs that represents the
 * height of rungs on a ladder. You are currently on the floor at height 0, and
 * you want to reach the last rung.
 *
 * You are also given an integer dist. You can only climb to the next highest
 * rung if the distance between where you are currently at (the floor or on a
 * rung) and the next rung is at most dist. You are able to insert rungs at any
 * positive integer height if a rung is not already there.
 *
 * Return the minimum number of rungs that must be added to the ladder in order
 * for you to climb to the last rung.
 *
 *
 * Example 1:
 *
 *
 * Input: rungs = [1,3,5,10], dist = 2
 * Output: 2
 * Explanation:
 * You currently cannot reach the last rung.
 * Add rungs at heights 7 and 8 to climb this ladder.
 * The ladder will now have rungs at [1,3,5,7,8,10].
 *
 *
 * Example 2:
 *
 *
 * Input: rungs = [3,6,8,10], dist = 3
 * Output: 0
 * Explanation:
 * This ladder can be climbed without adding additional rungs.
 *
 *
 * Example 3:
 *
 *
 * Input: rungs = [3,4,6,7], dist = 2
 * Output: 1
 * Explanation:
 * You currently cannot reach the first rung from the ground.
 * Add a rung at height 1 to climb this ladder.
 * The ladder will now have rungs at [1,3,4,6,7].
 *
 *
 * Example 4:
 *
 *
 * Input: rungs = [5], dist = 10
 * Output: 0
 * Explanation:
 * This ladder can be climbed without adding additional rungs.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= rungs.length <= 10^5
 * 1 <= rungs[i] <= 10^9
 * 1 <= dist <= 10^9
 * rungs is strictly increasing.
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int addRungs(vector<int> &rungs, int dist) {
        int res = 0;
        int curr = 0;
        for (int r : rungs) {
            if ((r - curr) <= dist) {
                curr = r;
            } else {
                // 注意不要用 while，会超时，直接相除即可
                // 如果没有余数的话还要 -1，因为最后一坎能自己上去
                int cnt = (r - curr) / dist;
                if ((r - curr) % dist == 0)
                    cnt--;
                res += cnt;
                curr = r;
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> vec = {10};
    Solution s;
    int ans = s.addRungs(vec, 5);
    return 0;
}
