/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (58.12%)
 * Likes:    3323
 * Dislikes: 95
 * Total Accepted:    546.4K
 * Total Submissions: 892.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        permutationCore(nums, 0, result);
        return result;
    }

  private:
    void permutationCore(vector<int> &item, int index, vector<vector<int>> &result) {
        if (index == item.size()) {
            result.push_back(item);
        } else {
            for (int i = index; i < item.size(); i++) {
                swap(item[i], item[index]);
                permutationCore(item, index + 1, result);
                swap(item[i], item[index]);
            }
        }
    }
};
// @lc code=end
