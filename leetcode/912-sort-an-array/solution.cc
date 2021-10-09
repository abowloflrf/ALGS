/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (56.31%)
 * Likes:    372
 * Dislikes: 0
 * Total Accepted:    217.9K
 * Total Submissions: 387.2K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order.
 *
 *
 * Example 1:
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Example 2:
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> sortArray(vector<int> &nums) {
        srand((unsigned)time(NULL));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

  private:
    void quickSort(vector<int> &nums, int start, int end) {
        if (start < end) {
            int p = partition(nums, start, end);
            quickSort(nums, start, p - 1);
            quickSort(nums, p + 1, end);
        }
    }
    int partition(vector<int> &nums, int start, int end) {
        // 1.取末尾数位基准
        // int pivot = end;

        // 2.随机取一位作为基准数，当遇到已经排好序的数组时，就退化为了 n^2
        // 因此随机选择基准，rand()=0至RAND_MAX
        int pivot = start + rand() % (end - start);
        swap(nums[end], nums[pivot]);
        pivot = end;

        int index = start;
        for (int i = start; i < end; i++) {
            if (nums[i] < nums[pivot]) {
                swap(nums[i], nums[index]);
                index++;
            }
        }
        swap(nums[index], nums[end]);
        return index;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> nums = {5, 2, 3, 1};
    Solution s;
    s.sortArray(nums);
    return 0;
}
