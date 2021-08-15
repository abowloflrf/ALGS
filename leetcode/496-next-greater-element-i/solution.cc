/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] Next Greater Element I
 *
 * https://leetcode-cn.com/problems/next-greater-element-i/description/
 *
 * algorithms
 * Easy (68.61%)
 * Likes:    465
 * Dislikes: 0
 * Total Accepted:    93.1K
 * Total Submissions: 135.7K
 * Testcase Example:  '[4,1,2]\n[1,3,4,2]'
 *
 * The next greater element of some element x in an array is the first greater
 * element that is to the right of x in the same array.
 *
 * You are given two distinct 0-indexed integer arrays nums1 and nums2, where
 * nums1 is a subset of nums2.
 *
 * For each 0 <= i < nums1.length, find the index j such that nums1[i] ==
 * nums2[j] and determine the next greater element of nums2[j] in nums2. If
 * there is no next greater element, then the answer for this query is -1.
 *
 * Return an array ans of length nums1.length such that ans[i] is the next
 * greater element as described above.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
 * Output: [-1,3,-1]
 * Explanation: The next greater element for each value of nums1 is as follows:
 * - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so
 * the answer is -1.
 * - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
 * - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so
 * the answer is -1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [2,4], nums2 = [1,2,3,4]
 * Output: [3,-1]
 * Explanation: The next greater element for each value of nums1 is as follows:
 * - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
 * - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so
 * the answer is -1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length <= nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 10^4
 * All integers in nums1 and nums2 are unique.
 * All the integers of nums1 also appear in nums2.
 *
 *
 *
 * Follow up: Could you find an O(nums1.length + nums2.length) solution?
 */
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        // 暴力解法：
        // vector<int> ans(nums1.size(), -1);
        // for (int i = 0; i < nums1.size(); i++) {
        //     bool found = false;
        //     for (int j = 0; j < nums2.size(); j++) {
        //         if (found) {
        //             if (nums2[j] > nums1[i]) {
        //                 ans[i] = nums2[j];
        //                 break;
        //             }
        //         } else {
        //             if (nums2[j] == nums1[i])
        //                 found = true;
        //         }
        //     }
        // }
        // return ans;

        // map + 单调栈
        vector<int> ans(nums1.size(), -1);
        stack<int> s;              // 栈中保存的元素是还没有找到下一个比它大的元素
        unordered_map<int, int> m; // 保存数组2中每个元素及其下一个比它大的元素映射关系

        for (auto const &i : nums2) {
            if (s.empty()) {
                s.push(i);
            }
            while (!s.empty() && s.top() < i) {
                m[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (!(m.find(nums1[i]) == m.end())) {
                ans[i] = m[nums1[i]];
            }
        }
        return ans;
    }
};
// @lc code=end
int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> nums1 = {1, 3, 5, 2, 4};
    vector<int> nums2 = {6, 5, 4, 2, 1, 3};
    auto a = s.nextGreaterElement(nums1, nums2);
    return 0;
}
