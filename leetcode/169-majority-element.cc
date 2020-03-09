/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (54.56%)
 * Likes:    2511
 * Dislikes: 206
 * Total Accepted:    515.1K
 * Total Submissions: 920K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3]
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 */

#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> m;
        int half = nums.size() / 2;
        for (auto n : nums) {
            if (m.find(n) == m.end())
                m.insert({n, 1});
            else
                m[n]++;
            if (m[n] > half)
                return n;
        }
        return -1;
    }
};
// @lc code=end

// 1. 暴力算法
// 2. hash表统计
// 3. 排序
// 4. 投票算法
