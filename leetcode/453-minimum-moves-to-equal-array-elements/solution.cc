/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 *
 * https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (55.65%)
 * Likes:    268
 * Dislikes: 0
 * Total Accepted:    29.1K
 * Total Submissions: 51.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of size n, return the minimum number of moves
 * required to make all array elements equal.
 *
 * In one move, you can increment n - 1 elements of the array by 1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 3
 * Explanation: Only three moves are needed (remember each move increments two
 * elements):
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,1,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * The answer is guaranteed to fit in a 32-bit integer.
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int minMoves(vector<int> &nums) {
        int minVal = INT32_MAX;
        int total = 0;
        for (auto n : nums) {
            minVal = min(minVal, n);
            total += n;
        }
        return total - minVal * nums.size();
    }
};
// @lc code=end
