/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (51.37%)
 * Likes:    11354
 * Dislikes: 0
 * Total Accepted:    2.2M
 * Total Submissions: 4.2M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 *
 *
 *
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time
 * complexity?
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // 将给定的 vector 容器中的数据储存到一个 unordered_map 中
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;
        // 对 map 进行一遍遍历
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = m.find(target - nums[i]);
            if (iter != m.end() && iter->second > i) {
                result.push_back(i);
                result.push_back(iter->second);
                break;
            }
        }
        return result;
    }
};
// @lc code=end
