/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (47.47%)
 * Likes:    1344
 * Dislikes: 320
 * Total Accepted:    205.8K
 * Total Submissions: 418.1K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * Example 1:
 *
 *
 * Input: [2,2,3,2]
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 *
 */
#include <unordered_map>
#include <vector>s
using namespace std;
// @lc code=start

// 看题解可以用位运算达到常数界别的空间复杂度。。。
class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> M;
        for (int n : nums) {
            if (M.find(n) != M.end()) {
                M[n]++;
            } else {
                M[n] = 1;
            }
        }
        for (auto m : M) {
            if (m.second != 3)
                return m.first;
        }
        return -1;
    }
};
// @lc code=end
