/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (30.02%)
 * Likes:    2881
 * Dislikes: 738
 * Total Accepted:    300.7K
 * Total Submissions: 969K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 *
 * Example 1:
 *
 *
 * Input: [1,2,0]
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: [3,4,-1,1]
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: [7,8,9,11,12]
 * Output: 1
 *
 *
 * Note:
 *
 * Your algorithm should run in O(n) time and uses constant extra space.
 *
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        // 使用额外的hash表储存元素，然后逐个判断是否存在
        unordered_set<int> S;
        for (int n : nums) {
            S.insert(n);
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (S.find(i) == S.end())
                return i;
        }
        return nums.size() + 1;
    }
};
// @lc code=end
