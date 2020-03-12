/*
 * @lc app=leetcode id=283 lang=cpp
 * LeetCode Link: https://leetcode.com/problems/move-zeroes/
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Note:
 *   1. You must do this in-place without making a copy of the array.
 *   2. Minimize the total number of operations.
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        int p = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                nums[p++] = nums[i];
        }
        for (int i = p; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> vec{1, 2, 3, 0, 0, 0, 1, 3, 0, 3, 4};
    s.moveZeroes(vec);

    return 0;
}