/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] The Skyline Problem
 *
 * https://leetcode-cn.com/problems/the-skyline-problem/description/
 *
 * algorithms
 * Hard (54.23%)
 * Likes:    556
 * Dislikes: 0
 * Total Accepted:    31.8K
 * Total Submissions: 58.6K
 * Testcase Example:  '[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]'
 *
 * A city's skyline is the outer contour of the silhouette formed by all the
 * buildings in that city when viewed from a distance. Given the locations and
 * heights of all the buildings, return the skyline formed by these buildings
 * collectively.
 *
 * The geometric information of each building is given in the array buildings
 * where buildings[i] = [lefti, righti, heighti]:
 *
 *
 * lefti is the x coordinate of the left edge of the i^th building.
 * righti is the x coordinate of the right edge of the i^th building.
 * heighti is the height of the i^th building.
 *
 *
 * You may assume all buildings are perfect rectangles grounded on an
 * absolutely flat surface at height 0.
 *
 * The skyline should be represented as a list of "key points" sorted by their
 * x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left
 * endpoint of some horizontal segment in the skyline except the last point in
 * the list, which always has a y-coordinate 0 and is used to mark the
 * skyline's termination where the rightmost building ends. Any ground between
 * the leftmost and rightmost buildings should be part of the skyline's
 * contour.
 *
 * Note: There must be no consecutive horizontal lines of equal height in the
 * output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is
 * not acceptable; the three lines of height 5 should be merged into one in the
 * final output as such: [...,[2 3],[4 5],[12 7],...]
 *
 *
 * Example 1:
 *
 *
 * Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
 * Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
 * Explanation:
 * Figure A shows the buildings of the input.
 * Figure B shows the skyline formed by those buildings. The red points in
 * figure B represent the key points in the output list.
 *
 *
 * Example 2:
 *
 *
 * Input: buildings = [[0,2,3],[2,5,3]]
 * Output: [[0,3],[5,0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= buildings.length <= 10^4
 * 0 <= lefti < righti <= 2^31 - 1
 * 1 <= heighti <= 2^31 - 1
 * buildings is sorted by lefti in non-decreasing order.
 *
 *
 */
#include <set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<pair<int, int>> v;
        for (auto &b : buildings) {
            // 楼开始设置为负数的原因是，pair 排序在 first 相等时，再按 second 小的在前
            // 但是实际上希望同一横坐标，最高的在前面
            v.push_back(make_pair(b[0], -b[2])); // 楼开始
            v.push_back(make_pair(b[1], b[2]));  // 楼结束
        }
        sort(v.begin(), v.end());

        // multiset 已经排好序，从前向后遍历，维护当时的最高值
        vector<vector<int>> ans;
        multiset<int> s;
        int prev = 0;
        for (auto &item : v) {
            if (item.second > 0) {
                s.erase(s.find(item.second));
            } else {
                s.insert(-item.second);
            }
            int h = 0;
            if (!s.empty())
                h = *s.rbegin();
            if (h != prev) {
                ans.push_back({item.first, h});
                prev = h;
            }
        }
        return ans;
    }
};
// @lc code=end
