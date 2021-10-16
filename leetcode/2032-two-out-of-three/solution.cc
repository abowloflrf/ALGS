/*
 * @lc app=leetcode.cn id=2032 lang=cpp
 *
 * [2032] Two Out of Three
 *
 * https://leetcode-cn.com/problems/two-out-of-three/description/
 *
 * algorithms
 * Easy (66.21%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 8K
 * Testcase Example:  '[1,1,3,2]\n[2,3]\n[3]'
 *
 * Given three integer arrays nums1, nums2, and nums3, return a distinct array
 * containing all the values that are present in at least two out of the three
 * arrays. You may return the values in any order.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
 * Output: [3,2]
 * Explanation: The values that are present in at least two arrays are:
 * - 3, in all three arrays.
 * - 2, in nums1 and nums2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
 * Output: [2,3,1]
 * Explanation: The values that are present in at least two arrays are:
 * - 2, in nums2 and nums3.
 * - 3, in nums1 and nums2.
 * - 1, in nums1 and nums3.
 *
 *
 * Example 3:
 *
 *
 * Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
 * Output: []
 * Explanation: No value is present in at least two arrays.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length, nums3.length <= 100
 * 1 <= nums1[i], nums2[j], nums3[k] <= 100
 *
 *
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3) {
        vector<int> ans;
        // value 001->1 010->2 100->4
        // map 保存目标数字与出现过的数组记录，分别用位表示出现过的三个数组，出现过则进行一次与运算
        // 然后一次遍历三个数组即可
        unordered_map<int, int> m;
        for (auto i : nums1) {
            auto iter = m.find(i);
            if (iter == m.end())
                m[i] = 1;
        }
        for (auto i : nums2) {
            auto iter = m.find(i);
            if (iter == m.end())
                m[i] = 2;
            else if (iter->second == 1) {
                ans.push_back(i);
                iter->second = 3;
            }
        }
        for (auto i : nums3) {
            auto iter = m.find(i);
            if (iter == m.end())
                continue;
            else if (iter->second == 1 || iter->second == 2) {
                ans.push_back(i);
                iter->second = iter->second & 4;
            }
        }
        return ans;
    }
};
// @lc code=end
