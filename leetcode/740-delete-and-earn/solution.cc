/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] Delete and Earn
 *
 * https://leetcode-cn.com/problems/delete-and-earn/description/
 *
 * algorithms
 * Medium (62.92%)
 * Likes:    450
 * Dislikes: 0
 * Total Accepted:    52.5K
 * Total Submissions: 83.5K
 * Testcase Example:  '[3,4,2]'
 *
 * You are given an integer array nums. You want to maximize the number of
 * points you get by performing the following operation any number of
 * times:
 *
 *
 * Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must
 * delete every element equal to nums[i] - 1 and every element equal to nums[i]
 * + 1.
 *
 *
 * Return the maximum number of points you can earn by applying the above
 * operation some number of times.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,4,2]
 * Output: 6
 * Explanation: You can perform the following operations:
 * - Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
 * - Delete 2 to earn 2 points. nums = [].
 * You earn a total of 6 points.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,3,3,3,4]
 * Output: 9
 * Explanation: You can perform the following operations:
 * - Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums =
 * [3,3].
 * - Delete a 3 again to earn 3 points. nums = [3].
 * - Delete a 3 once more to earn 3 points. nums = [].
 * You earn a total of 9 points.
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i] <= 10^4
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int deleteAndEarn(vector<int> &nums) {
        // 统计相同数字出现的个数 value->count 的关系
        // 用数组有两个好处
        // 1. 简化哈希表，迅速定位
        // 2. 快速知道 value 相邻的元素有没有出现过，即 count 是否为 0
        int data[10001];
        memset(data, 0, sizeof(data));
        int maxData = 0;
        int minData = INT32_MAX;
        for (auto n : nums) {
            data[n] += n;
            maxData = max(maxData, n);
            minData = min(minData, n);
        }

        // dp[i] 为前 i 个数的结果，要么隔一个取，要么隔两个取
        for (int i = minData; i <= maxData; i++) {
            // 直接用原数组做滚动 dp，不需要新的 dp 数组了
            data[i] = max(data[i - 1], data[i - 2] + data[i]);
        }
        return data[maxData];
    }
};
// @lc code=end
int main(int argc, char const *argv[]) {

    Solution s;
    // vector<int> data = {10, 8, 4,  2, 1, 3,  4, 8,  2, 9, 10, 4, 8, 5,  9, 1, 5, 1,  6, 8,  1,  1, 6,  7, 8,
    //                     9,  1, 7,  6, 8, 4,  5, 4,  1, 5, 9,  8, 6, 10, 6, 4, 3, 8,  4, 10, 8,  8, 10, 6, 4,
    //                     4,  4, 9,  6, 9, 10, 7, 1,  5, 3, 4,  4, 8, 1,  1, 2, 1, 4,  1, 1,  4,  9, 4,  7, 1,
    //                     5,  1, 10, 3, 5, 10, 3, 10, 2, 1, 10, 4, 1, 1,  4, 1, 2, 10, 9, 7,  10, 1, 2,  7, 5};
    vector<int> data = {2, 2, 3, 3, 3, 4};
    s.deleteAndEarn(data);
    return 0;
}
