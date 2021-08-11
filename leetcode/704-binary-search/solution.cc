/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] Binary Search
 *
 * https://leetcode-cn.com/problems/binary-search/description/
 *
 * algorithms
 * Easy (55.71%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    189.2K
 * Total Submissions: 340.1K
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * Given an array of integers nums which is sorted in ascending order, and an
 * integer target, write a function to search target in nums. If target exists,
 * then return its index. Otherwise, return -1.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 < nums[i], target < 10^4
 * All the integers in nums are unique.
 * nums is sorted in ascending order.
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int idx = left + (right - left) / 2;
            if (nums[idx] == target) {
                return idx;
            }
            if (nums[idx] < target) {
                left = idx + 1;
            } else {
                right = idx - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> input = {12};
    int r = s.search(input, 12);
    return 0;
}
