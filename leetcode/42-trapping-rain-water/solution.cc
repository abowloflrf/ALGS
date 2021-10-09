/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (58.03%)
 * Likes:    2719
 * Dislikes: 0
 * Total Accepted:    325K
 * Total Submissions: 560K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int trap(vector<int> &height) {
        // 1. 找到最高点
        int highest = -1;
        int highestIdx = -1;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > highest) {
                highestIdx = i;
                highest = height[i];
            }
        }

        int ans = 0;
        // 2. 从左右分别开始往中间走，并维护者左边的最高值和右边的最高值
        // 2.1 从左边到中间
        int lmax = height[0];
        for (int i = 0; i < highestIdx; i++) {
            if (height[i] > lmax) {
                lmax = height[i];
            } else {
                ans += (lmax - height[i]);
            }
        }
        // 2.2 从右边到中间
        int rmax = height.back();
        for (int i = height.size() - 1; i > highestIdx; i--) {
            if (height[i] > rmax) {
                rmax = height[i];
            } else {
                ans += (rmax - height[i]);
            }
        }

        return ans;
    }
};
// @lc code=end
