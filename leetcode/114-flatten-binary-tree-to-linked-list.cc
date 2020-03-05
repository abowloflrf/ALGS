/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (46.27%)
 * Likes:    2211
 * Dislikes: 275
 * Total Accepted:    303.2K
 * Total Submissions: 651.8K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example, given the following tree:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 *
 *
 * The flattened tree should look like:
 *
 *
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 *
 *
 */

#include "./utils/tree.h"

class Solution1 {
  public:
    TreeNode *tmp = nullptr;
    void flatten(TreeNode *root) {
        if (root == nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = tmp;
        root->left = nullptr;
        tmp = root;
    }
};
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
    void flatten(TreeNode *root) {
        while (root != nullptr) {
            if (root->left != nullptr) {
                //找到左子树的最右节点
                TreeNode *mostRight = root->left;
                while (mostRight->right != nullptr)
                    mostRight = mostRight->right;
                // 将右子树放在左子树最右节点的右边
                mostRight->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
// @lc code=end
