/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.98%)
 * Likes:    846
 * Dislikes: 0
 * Total Accepted:    243.5K
 * Total Submissions: 529.5K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an integer array nums of length n and an integer target, find three
 * integers in nums such that the sum is closest to target.
 *
 * Return the sum of the three integers.
 *
 * You may assume that each input would have exactly one solution.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,0,0], target = 1
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 *
 *
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());

        // 这里注意题目给出的 target 范围 -10^4 <= target <= 10^4
        // 数据范围 -1000 <= nums[i] <= 1000
        // 因此最大差异不会超过 10000 + 3*1000
        int closet = 100000;
        for (int i = 0; i < nums.size(); i++) {
            int a = i;
            int b = i + 1;
            int c = nums.size() - 1;
            while (b < c) {
                int sum = nums[i] + nums[b] + nums[c];
                if (abs(sum - target) < abs(closet - target)) {
                    closet = sum;
                }
                if (sum > target) {
                    c--;
                } else if (sum < target) {
                    b++;
                } else {
                    return target;
                }
            }
        }
        return closet;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> input = {1, 1, 1, 1};
    int ans = s.threeSumClosest(input, -100);
    return 0;
}
