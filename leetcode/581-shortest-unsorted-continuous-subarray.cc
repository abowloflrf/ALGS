/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (30.54%)
 * Likes:    1745
 * Dislikes: 79
 * Total Accepted:    84.6K
 * Total Submissions: 277K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 * Example 1:
 *
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 *
 *
 *
 * Note:
 *
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means .
 *
 *
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    int findUnsortedSubarray(vector<int> &nums) {
        // 从两端找到首个开始乱序的数字以及其位置
        int size = nums.size();
        int leftPosition = 0, rightPosition = size - 1;
        while (leftPosition < size - 1 && nums[leftPosition + 1] >= nums[leftPosition])
            leftPosition++;
        if (leftPosition == size - 1)
            return 0;
        while (rightPosition > 0 && nums[rightPosition - 1] <= nums[rightPosition])
            rightPosition--;

        // 找到left - right 区间内的最大值和最小值
        int maxValue = nums[leftPosition], minValue = nums[leftPosition];
        for (int i = leftPosition; i <= rightPosition; i++) {
            if (nums[i] > maxValue)
                maxValue = nums[i];
            if (nums[i] < minValue)
                minValue = nums[i];
        }
        // 从最左向右开始找到首个大于min的位置
        for (int i = 0; i < leftPosition; i++) {
            if (nums[i] > minValue) {
                leftPosition = i;
                break;
            }
        }

        // 右边同理，从最右向左找到首个小于max的位置
        for (int i = size - 1; i > rightPosition; i--) {
            if (nums[i] < maxValue) {
                rightPosition = i;
                break;
            }
        }

        return rightPosition - leftPosition + 1;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    Solution s;
    vector<int> nums{1};
    // vector<int> nums{1, 2, 3, 4};
    // vector<int> nums{2, 6, 4, 8, 10, 9, 15};
    int r = s.findUnsortedSubarray(nums);
    cout << r;
    return 0;
}
