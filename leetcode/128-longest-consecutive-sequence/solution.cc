/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (54.33%)
 * Likes:    919
 * Dislikes: 0
 * Total Accepted:    170.2K
 * Total Submissions: 313.2K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
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
        if (nums.empty())
            return 0;

        unordered_set<int> s;
        for (int n : nums) {
            s.insert(n);
        }

        int maxLen = 1;
        for (int n : nums) {
            // 若 n-1 存在说明不是开头，直接跳过不判断
            if (s.find(n - 1) != s.end()) {
                continue;
            }
            int curLen = 1;
            while (s.find(++n) != s.end()) {
                curLen++;
                if (curLen > maxLen) {
                    maxLen = curLen;
                }
            }
        }
        return maxLen;
    }
};
// @lc code=end
