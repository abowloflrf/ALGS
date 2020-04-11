/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (45.31%)
 * Likes:    6030
 * Dislikes: 107
 * Total Accepted:    455.5K
 * Total Submissions: 963.2K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 *
 * Example:
 *
 *
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int trap(vector<int> &height) {
        if (height.size() <= 2)
            return 0;

        int res = 0;
        // 先找到最高点
        int maxHeight = height[0], maxIdx = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > maxHeight) {
                maxIdx = i;
                maxHeight = height[i];
            }
        }
        // 然后从两边开始向中间的最高点计算，向中间靠拢计算的同时维护者左右两边的最高点

        // 从左到中间
        int lmax = height[0];
        for (int i = 0; i < maxIdx; i++) {
            if (height[i] < lmax) {
                res += (lmax - height[i]);
            } else {
                lmax = height[i];
            }
        }
        // 从右到中间
        int rmax = height.back();
        for (int i = height.size() - 1; i > maxIdx; i--) {
            if (height[i] < rmax) {
                res += (rmax - height[i]);
            } else {
                rmax = height[i];
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int r = s.trap(h);
    return 0;
}