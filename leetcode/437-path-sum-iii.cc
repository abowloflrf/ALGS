/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (43.97%)
 * Likes:    2299
 * Dislikes: 137
 * Total Accepted:    129.5K
 * Total Submissions: 294.3K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 *
 * Find the number of paths that sum to a given value.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 *
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 *
 * Example:
 *
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 *
 * Return 3. The paths that sum to 8 are:
 *
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
 *
 *
 */

#include "utils/tree.h"

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    int pathSum(TreeNode *root, int sum) {
        dfs(root, sum);
        return ans;
    }

  private:
    int ans = 0;
    void dfs(TreeNode *root, int sum) {
        if (!root)
            return;
        pathFromRoot(root, sum);
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
    // 从root节点开始的和为sum的路径数量
    void pathFromRoot(TreeNode *root, int sum) {
        if (!root)
            return;
        if (root->val == sum)
            ans++;
        int leftSum = sum - root->val;
        pathFromRoot(root->left, leftSum);
        pathFromRoot(root->right, leftSum);
    }
};
// @lc code=end
