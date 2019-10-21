/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (54.38%)
 * Likes:    1920
 * Dislikes: 178
 * Total Accepted:    183.9K
 * Total Submissions: 338.1K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once.
 *
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 *
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 *
 * Example:
 *
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [5,6]
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        // 所有的数都是正整数 1-n
        // 有的数出现1次（奇数）
        // 有的数出现2次（偶数）

        // value-1的位置翻转一下，value-1出现2次的位置会翻转两次变成正数
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            // 若小于0说明已经是翻转的第二遍了，为了避免和没有翻转过的混淆，第二次翻转不做处理
            if (nums[index] < 0)
                continue;
            nums[index] = -nums[index];
        }
        vector<int> res;
        // 还为正数的是翻转次数为0的位置的数
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                res.push_back(i + 1);
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> vec{1, 2, 2};
    Solution s;
    auto r = s.findDisappearedNumbers(vec);
    return 0;
}
