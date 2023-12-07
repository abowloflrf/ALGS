/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.cn/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (63.53%)
 * Likes:    2244
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.9M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an integer array nums, move all 0's to the end of it while maintaining
 * the relative order of the non-zero elements.
 *
 * Note that you must do this in-place without making a copy of the array.
 *
 *
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you minimize the total number of operations done?
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    // 直接从前往后依次赋值非0的数，最后再将0补齐
    void moveZeroes(vector<int> &nums) {
        int p = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[p] = nums[i];
                p++;
            }
        }
        for (int i = p; i < nums.size(); i++) {
            nums[p] = 0;
        }
    }
};
// @lc code=end

// 两两交换的解法，效率一般
class Solution2 {
  public:
    void moveZeroes(vector<int> &nums) {
        int firstIdx = 0;
        int secondIdx = 0;
        while (secondIdx < nums.size()) {
            // 找到第一个0，和这个0后第一个非0
            bool foundZero = false;
            for (int i = firstIdx; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    foundZero = true;
                    firstIdx = i;
                    break;
                }
            }
            if (!foundZero) {
                return;
            }
            bool foundNoneZero = false;
            for (int i = firstIdx + 1; i < nums.size(); i++) {
                if (nums[i] != 0) {
                    foundNoneZero = true;
                    secondIdx = i;
                    break;
                }
            }
            if (!foundNoneZero) {
                return;
            }
            swap(nums[firstIdx], nums[secondIdx]);
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> input = {0, 1, 0, 3, 12};
    s.moveZeroes(input);
    return 0;
}
