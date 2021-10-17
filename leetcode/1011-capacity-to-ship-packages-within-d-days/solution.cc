/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 *
 * https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/description/
 *
 * algorithms
 * Medium (62.63%)
 * Likes:    398
 * Dislikes: 0
 * Total Accepted:    60.6K
 * Total Submissions: 96.8K
 * Testcase Example:  '[1,2,3,4,5,6,7,8,9,10]\n5'
 *
 * A conveyor belt has packages that must be shipped from one port to another
 * within days days.
 *
 * The i^th package on the conveyor belt has a weight of weights[i]. Each day,
 * we load the ship with packages on the conveyor belt (in the order given by
 * weights). We may not load more weight than the maximum weight capacity of
 * the ship.
 *
 * Return the least weight capacity of the ship that will result in all the
 * packages on the conveyor belt being shipped within days days.
 *
 *
 * Example 1:
 *
 *
 * Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
 * Output: 15
 * Explanation: A ship capacity of 15 is the minimum to ship all the packages
 * in 5 days like this:
 * 1st day: 1, 2, 3, 4, 5
 * 2nd day: 6, 7
 * 3rd day: 8
 * 4th day: 9
 * 5th day: 10
 *
 * Note that the cargo must be shipped in the order given, so using a ship of
 * capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6,
 * 7), (8), (9), (10) is not allowed.
 *
 *
 * Example 2:
 *
 *
 * Input: weights = [3,2,2,4,1,4], days = 3
 * Output: 6
 * Explanation: A ship capacity of 6 is the minimum to ship all the packages in
 * 3 days like this:
 * 1st day: 3, 2
 * 2nd day: 2, 4
 * 3rd day: 1, 4
 *
 *
 * Example 3:
 *
 *
 * Input: weights = [1,2,3,1,1], days = 4
 * Output: 3
 * Explanation:
 * 1st day: 1
 * 2nd day: 2
 * 3rd day: 3
 * 4th day: 1, 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= days <= weights.length <= 5 * 10^4
 * 1 <= weights[i] <= 500
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int shipWithinDays(vector<int> &weights, int days) {
        // 找到最大重量
        int maxweight = 0;
        int sumweight = 0;
        for (int w : weights) {
            maxweight = max(w, maxweight);
            sumweight += w;
        }
        // 目标运载能力在 [maxweight, sumweight] 之间
        // 两个边界分别需要 weights.size() 天 和 1 天完成

        // 在 maxweight maxweight 作为左右边界使用二分查找满足小于目标 days 的承重量
        int left = maxweight, right = sumweight;
        while (left < right) {
            int mid = left + (right - left) / 2;

            // 选择 mid 时，计算需要运载完成的最小天数
            int currentDays = 1;
            int currentWeight = 0;
            for (int w : weights) {
                if (currentWeight + w > mid) {
                    currentDays++;
                    currentWeight = w;
                } else {
                    currentWeight += w;
                }
            }
            if (currentDays <= days) {
                // 需要的天数小于或等于目标，满足要求，mid 不要减一，否则可能就不满足了
                right = mid;
            } else {
                // 需要的天数大于目标，不满足要求
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
