/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode-cn.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (43.07%)
 * Likes:    1219
 * Dislikes: 0
 * Total Accepted:    209.7K
 * Total Submissions: 486.7K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers nums, you are initially positioned
 * at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * You can assume that you can always reach the last index.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump
 * 1 step from index 0 to 1, then 3 steps to the last index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int jump(vector<int> &nums) {
        // 贪心算法即可
        int count = 0;
        int idx = 0;

        while (idx < nums.size()) {
            // 输入为 [0] 时，开始就在终点
            if (idx == nums.size() - 1) {
                return count;
            }
            // 当前位置能直接到终点，则一步到位
            if (nums[idx] + idx >= nums.size() - 1) {
                return count + 1;
            }
            // targeti 为目标下一个的位置，nextii 为下下个最大的位置
            // 因此从 idx 到 idx+nums[idx] 中选出能使得 nextii 最大的位置跳（贪心）
            int targeti = -1, nextii = -1;
            for (int i = idx; i <= nums[idx] + idx; i++) {
                if (nums[i] + i > nextii) {
                    targeti = i;
                    nextii = (nums[i] + i);
                }
            }
            count++;
            idx = targeti;
        }
        return count;
    }
};
// @lc code=end
