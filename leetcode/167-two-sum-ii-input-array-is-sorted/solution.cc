/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (58.64%)
 * Likes:    570
 * Dislikes: 0
 * Total Accepted:    270K
 * Total Submissions: 460.4K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers numbers that is already sorted in non-decreasing
 * order, find two numbers such that they add up to a specific target number.
 *
 * Return the indices of the two numbers (1-indexed) as an integer array answer
 * of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.
 *
 * The tests are generated such that there is exactly one solution. You may not
 * use the same element twice.
 *
 *
 * Example 1:
 *
 *
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: numbers = [2,3,4], target = 6
 * Output: [1,3]
 *
 *
 * Example 3:
 *
 *
 * Input: numbers = [-1,0], target = -1
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= numbers.length <= 3 * 10^4
 * -1000 <= numbers[i] <= 1000
 * numbers is sorted in non-decreasing order.
 * -1000 <= target <= 1000
 * The tests are generated such that there is exactly one solution.
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        while (start < end) {
            if (numbers[start] + numbers[end] == target) {
                return {start + 1, end + 1};
            } else if (numbers[start] + numbers[end] < target) {
                start++;
            } else if (numbers[start] + numbers[end] > target) {
                end--;
            }
        }
        return {-1, -1};
    }
};
// @lc code=end
