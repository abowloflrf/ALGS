/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (50.93%)
 * Likes:    903
 * Dislikes: 0
 * Total Accepted:    240.7K
 * Total Submissions: 472.5K
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 * There are some spherical balloons taped onto a flat wall that represents the
 * XY-plane. The balloons are represented as a 2D integer array points where
 * points[i] = [xstart, xend] denotes a balloon whose horizontal diameter
 * stretches between xstart and xend. You do not know the exact y-coordinates
 * of the balloons.
 *
 * Arrows can be shot up directly vertically (in the positive y-direction) from
 * different points along the x-axis. A balloon with xstart and xend is burst
 * by an arrow shot at x if xstart <= x <= xend. There is no limit to the
 * number of arrows that can be shot. A shot arrow keeps traveling up
 * infinitely, bursting any balloons in its path.
 *
 * Given the array points, return the minimum number of arrows that must be
 * shot to burst all balloons.
 *
 *
 * Example 1:
 *
 *
 * Input: points = [[10,16],[2,8],[1,6],[7,12]]
 * Output: 2
 * Explanation: The balloons can be burst by 2 arrows:
 * - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
 * - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
 *
 *
 * Example 2:
 *
 *
 * Input: points = [[1,2],[3,4],[5,6],[7,8]]
 * Output: 4
 * Explanation: One arrow needs to be shot for each balloon for a total of 4
 * arrows.
 *
 *
 * Example 3:
 *
 *
 * Input: points = [[1,2],[2,3],[3,4],[4,5]]
 * Output: 2
 * Explanation: The balloons can be burst by 2 arrows:
 * - Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
 * - Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= points.length <= 10^5
 * points[i].length == 2
 * -2^31 <= xstart < xend <= 2^31 - 1
 *
 *
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start

// 对气球的开始x坐标排序
static bool comp(const vector<int> &a, const vector<int> &b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

class Solution {
  public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), comp);
        int ans = 1;
        int left = points[0][0];
        int right = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > right) {
                // 和上一个无重叠
                left = points[i][0];
                right = points[i][1];
                ans++;
            } else {
                // 和上一个有重叠
                left = points[i][0];
                right = min(right, points[i][1]);
            }
        }
        return ans;
    }
};
// @lc code=end
