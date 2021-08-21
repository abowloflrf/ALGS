/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (75.87%)
 * Likes:    816
 * Dislikes: 0
 * Total Accepted:    181.5K
 * Total Submissions: 239.2K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an integer array nums where the elements are sorted in ascending
 * order, convert it to a height-balanced binary search tree.
 *
 * A height-balanced binary tree is a binary tree in which the depth of the two
 * subtrees of every node never differs by more than one.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 * Explanation: [0,-10,5,null,-3,null,9] is also accepted:
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,3]
 * Output: [3,1]
 * Explanation: [1,3] and [3,1] are both a height-balanced BSTs.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in a strictly increasing order.
 *
 *
 */
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums) { return dfs(nums, 0, nums.size() - 1); }

  private:
    TreeNode *dfs(vector<int> &nums, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }
        int mid = lo + (hi - lo) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = dfs(nums, lo, mid - 1);
        node->right = dfs(nums, mid + 1, hi);
        return node;
    }
};
// @lc code=end
