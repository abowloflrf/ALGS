/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode-cn.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (72.54%)
 * Likes:    436
 * Dislikes: 0
 * Total Accepted:    50.1K
 * Total Submissions: 69K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an integer array nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once. You can return the answer in any order.
 *
 * You must write an algorithm that runs in linear runtime complexity and uses
 * only constant extra space.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,1,3,2,5]
 * Output: [3,5]
 * Explanation:  [5, 3] is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,0]
 * Output: [-1,0]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,1]
 * Output: [1,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each integer in nums will appear twice, only two integers will appear once.
 *
 *
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> singleNumber2(vector<int> &nums) {
        unordered_set<int> S;
        for (auto n : nums) {
            if (S.find(n) == S.end()) {
                S.insert(n);
            } else {
                S.erase(n);
            }
        }
        vector<int> ans;
        for (auto n : S) {
            ans.push_back(n);
        }
        return ans;
    }
    // 打死也想不到的方法
    vector<int> singleNumber(vector<int> &nums) {
        int m = 0;
        for (auto n : nums) {
            m ^= n;
        }
        // 从低到高找到第一位非0的位置，初始为第一位
        int bitPosition = 1;
        while ((m & 1) == 0) {
            m >>= 1;           // 原数少一位
            bitPosition <<= 1; // 位置多一位
        }
        // 分两种情况再次遍历异或，相同的数字必然还是抵消，唯一的数字最后为出现
        int a = 0, b = 0;
        for (auto n : nums) {
            if ((n & bitPosition) == 0) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        return {a, b};
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> v = {1, 2, 5, 2};
    auto a = s.singleNumber(v);
    return 0;
}