/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.03%)
 * Likes:    5990
 * Dislikes: 730
 * Total Accepted:    822.9K
 * Total Submissions: 3.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;

        // 先对原数组排序
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // 由于已经排序，若n1都大于0，后面的所有数都会大于0不可能有新的解了，直接结束循环
            if (nums[i] > 0)
                break;
            // 去除重复的n1
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // 第一个数n1已经确定，目标为 n2+n3=-n1
            int target = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int s = nums[left] + nums[right];
                // 后两数和正好等于目标，得到一个解
                if (s == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // 消除重复的n2 n3
                    while (left < right && nums[left + 1] == nums[left])
                        left++;
                    while (left < right && nums[right - 1] == nums[right])
                        right--;
                    // 左右指针向中间走继续判断
                    left++;
                    right--;
                } else if (s < target) {
                    // 后两数过小，n2不够大，左指针向右走
                    left++;
                } else {
                    // 后两数过大，n3过大，右指针向左走
                    right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
