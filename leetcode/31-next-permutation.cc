/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.22%)
 * Likes:    2314
 * Dislikes: 755
 * Total Accepted:    283.4K
 * Total Submissions: 907.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        const int size = nums.size();
        for (int i = size - 1; i > 0; i--) {
            // 先从右开始向左找到首个开始递减的数
            if (nums[i - 1] < nums[i]) {
                // 若找到次数为 nums[i-1]，再从nums[i]向右找到最后一个大于它的数进行交换
                for (int j = i; j < nums.size(); j++) {
                    if (nums[j] <= nums[i - 1]) {
                        swap(nums[j - 1], nums[i - 1]);
                        break;
                    } else if (j == nums.size() - 1) {
                        swap(nums[j], nums[i - 1]);
                    }
                }
                // 翻转i-1右边的排列
                for (int k = 0; k < (size - i) / 2; k++) {
                    swap(nums[i + k], nums[size - 1 - k]);
                }
                return;
            }
        }
        // 遍历一遍都没有找到要交换的数字，说明此排列已经为降序排列的最大值，则翻转为最小值
        for (int i = 0; i < size / 2; i++) {
            swap(nums[i], nums[size - 1 - i]);
        }
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> vec{4, 2, 9, 5, 8, 4, 7, 5, 1};
    // vector<int> vec{1, 3, 1, 2, 6, 7, 7};
    Solution s;
    s.nextPermutation(vec);
    return 0;
}
