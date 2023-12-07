/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 *
 * https://leetcode.cn/problems/max-consecutive-ones-iii/description/
 *
 * algorithms
 * Medium (59.30%)
 * Likes:    661
 * Dislikes: 0
 * Total Accepted:    144.7K
 * Total Submissions: 244K
 * Testcase Example:  '[1,1,1,0,0,0,1,1,1,1,0]\n2'
 *
 * Given a binary array nums and an integer k, return the maximum number of
 * consecutive 1's in the array if you can flip at most k 0's.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output: 6
 * Explanation: [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is
 * underlined.
 *
 * Example 2:
 *
 *
 * Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * Output: 10
 * Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is
 * underlined.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 0 <= k <= nums.length
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int longestOnes(vector<int> &nums, int k) {
        int left = 0;
        int right = 0;
        int numZero = 0;
        int maxOne = 0;
        // 1 的数量就是 right - left + 1
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                numZero++;
            }
            if (numZero > k) {
                for (int j = left; j < nums.size(); j++) {
                    if (nums[j] == 0) {
                        numZero--;
                        left = j + 1;
                        break;
                    }
                }
            }
            maxOne = max(maxOne, right - left + 1);
        }
        return maxOne;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> input = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    s.longestOnes(input, 2);
    return 0;
}
