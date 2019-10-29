/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (26.50%)
 * Likes:    2538
 * Dislikes: 372
 * Total Accepted:    499.1K
 * Total Submissions: 1.9M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 *
 * Input: [2,1,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 *
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 *
 *
 */

#include "utils/tree.h"
#include <stack>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    bool isValidBST(TreeNode *root) {
        // BST DFS 中序遍历，就是一个递增的数列
        // 递归方法，没有使用额外的空间
        inOrderRecursive(root);
        return !inValid;
    }

  private:
    bool inValid = false;
    TreeNode *last;
    void inOrderRecursive(TreeNode *node) {
        if (node == nullptr || inValid)
            return;
        inOrderRecursive(node->left);
        if (last && last->val >= node->val) {
            inValid = true;
            return;
        }
        last = node;
        inOrderRecursive(node->right);
    }
};
// @lc code=end

class Solution2 {
  public:
    bool isValidBST(TreeNode *root) {
        // BST DFS 中序遍历，就是一个递增的数列
        // 非递归方法，使用了额外的空间stack O(n)
        TreeNode *last = nullptr;
        stack<TreeNode *> s;
        TreeNode *node = root;
        while (node != nullptr || !s.empty()) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();

            if (last && last->val >= node->val)
                return false;
            last = node;

            node = node->right;
        }
        return true;
    }
};