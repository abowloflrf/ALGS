/*
 * @lc app=leetcode id=836 lang=cpp
 *
 * [836] Rectangle Overlap
 *
 * https://leetcode.com/problems/rectangle-overlap/description/
 *
 * algorithms
 * Easy (47.54%)
 * Likes:    542
 * Dislikes: 99
 * Total Accepted:    42.1K
 * Total Submissions: 86.7K
 * Testcase Example:  '[0,0,2,2]\n[1,1,3,3]'
 *
 * A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are
 * the coordinates of its bottom-left corner, and (x2, y2) are the coordinates
 * of its top-right corner.
 *
 * Two rectangles overlap if the area of their intersection is positive.  To be
 * clear, two rectangles that only touch at the corner or edges do not
 * overlap.
 *
 * Given two (axis-aligned) rectangles, return whether they overlap.
 *
 * Example 1:
 *
 *
 * Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
 * Output: false
 *
 *
 * Notes:
 *
 *
 * Both rectangles rec1 and rec2 are lists of 4 integers.
 * All coordinates in rectangles will be between -10^9 and 10^9.
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
        // 非 未重叠的情形
        return !(rec2[1] >= rec1[3] || rec2[3] <= rec1[1] || rec2[0] >= rec1[2] || rec2[2] <= rec1[0]);
    }
};
// @lc code=end
