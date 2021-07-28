/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (42.99%)
 * Likes:    2676
 * Dislikes: 152
 * Total Accepted:    266.5K
 * Total Submissions: 606.6K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * Example:
 *
 *
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 */

#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        // 先将所有数保存到一个unordered_set里，方便查找，顺便能去重
        unordered_set<int> S;
        for (int n : nums) {
            S.insert(n);
        }

        int res = 1;
        for (int n : nums) {
            // 这个剪枝条件非常关键，保证这次计算的是连续序列的开始一个数
            if (S.find(n - 1) == S.end()) { 
                // 然后向后递增1判断是否在set里存在，并维护最长连续长度
                int curr = n;
                int currMax = 1;
                while (S.find(n + 1) != S.end()) {
                    n++;
                    currMax++;
                }
                res = max(res, currMax);
            }
        }
        return res;
    }
};
// @lc code=end
