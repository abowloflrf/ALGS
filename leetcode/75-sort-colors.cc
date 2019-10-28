/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (43.57%)
 * Likes:    2094
 * Dislikes: 179
 * Total Accepted:    370.8K
 * Total Submissions: 850.6K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 *
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 *
 * Example:
 *
 *
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 *
 * Follow up:
 *
 *
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int i = 0, j = 0, k = nums.size() - 1;
        while (j < k) {
            switch (nums[j]) {
            case 0:
                swap(nums[j++], nums[i++]);
                break;
            case 1:
                j++;
                break;
            case 2:
                swap(nums[j], nums[k--]);
                break;
            }
        }
    }
};
// @lc code=end

class Solution2 {
  public:
    void sortColors(vector<int> &nums) {
        if (nums.size() < 2)
            return;
        int indexLeft = 0;
        int indexRight = nums.size() - 1;
        int index_0 = -1;
        int index_2 = nums.size();
        while (indexLeft <= indexRight) {
            if (nums[indexLeft] == 0) {
                swap(nums[indexLeft++], nums[++index_0]);
            } else if (nums[indexLeft] == 2) {
                // 与右边indexRight开始第一个非2的数交换
                while (nums[indexRight] == 2) {
                    index_2 = indexRight--;
                }
                if (indexLeft < indexRight) {
                    if (nums[indexRight] == 0) {
                        //右边是0，2换0
                        swap(nums[--index_2], nums[indexLeft]);
                        swap(nums[++index_0], nums[indexLeft]);
                        indexRight--;
                        indexLeft++;
                    } else {
                        //右边是1，2换1
                        swap(nums[indexLeft], nums[--index_2]);
                        indexLeft++;
                        indexRight--;
                    }
                }
            } else {
                indexLeft++;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    vector<int> vec{2, 2};
    Solution s;
    s.sortColors(vec);
    for (auto i : vec)
        cout << i;
    return 0;
}
