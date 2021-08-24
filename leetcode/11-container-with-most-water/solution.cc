/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (63.22%)
 * Likes:    2723
 * Dislikes: 0
 * Total Accepted:    510K
 * Total Submissions: 806.7K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which,
 * together with the x-axis forms a container, such that the container contains
 * the most water.
 *
 * Notice that you may not slant the container.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [1,1]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: height = [4,3,2,1,4]
 * Output: 16
 *
 *
 * Example 4:
 *
 *
 * Input: height = [1,2,1]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int maxArea(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while (left < right) {
            // 当前的最短高度
            int h = min(height[left], height[right]);
            int current = (right - left) * h;
            if (current > res)
                res = current;
            while (left < right && height[left ] <= h)
                left++;
            while (left < right && height[right ] <= h)
                right--;
        }
        return res;
    }
};
// @lc code=end
