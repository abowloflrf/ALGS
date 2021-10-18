/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] Contiguous Array
 *
 * https://leetcode-cn.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (53.60%)
 * Likes:    472
 * Dislikes: 0
 * Total Accepted:    45.5K
 * Total Submissions: 84.9K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array nums, return the maximum length of a contiguous
 * subarray with an equal number of 0 and 1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with an equal number
 * of 0 and 1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 *
 *
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int prefix = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                prefix--;
            } else {
                prefix++;
            }
            // 从前面找
            if (m.find(prefix) != m.end()) {
                ans = max(ans, i - m[prefix]);
            } else {
                m[prefix] = i;
            }
        }
        return ans;
    }
};
// @lc code=end
