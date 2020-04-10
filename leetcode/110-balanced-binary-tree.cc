/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (41.92%)
 * Likes:    1897
 * Dislikes: 150
 * Total Accepted:    414.2K
 * Total Submissions: 968.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as:
 *
 *
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 *
 *
 *
 *
 * Example 1:
 *
 * Given the following tree [3,9,20,null,null,15,7]:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * Return true.
 *
 * Example 2:
 *
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 *
 *
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 *
 *
 * Return false.
 *
 */
#include "./utils/tree.h"
#include <iostream>
#include <unordered_map>
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
// 自底向上
class Solution {
  public:
    bool isBalanced(TreeNode *root) {
        int h;
        return helper(root, h);
    }

  private:
    // 返回root树是否为balanced，以及它的高度，
    // 由于c++无法返回两个值，简单将要返回的高度作为引用传入到参数中
    bool helper(TreeNode *root, int &height) {
        if (root == nullptr) {
            height = -1;
            return true;
        }
        int leftHeight, rightHeight;
        if (helper(root->left, leftHeight) && helper(root->right, rightHeight) && abs(leftHeight - rightHeight) <= 1) {
            height = max(leftHeight, rightHeight) + 1;
            return true;
        }
        return false;
    }
};
// @lc code=end

// 自顶向下
class Solution2 {
  public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr)
            return true;
        return abs(height(root->left) - height(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }

  private:
    unordered_map<TreeNode *, int> mem;
    int height(TreeNode *root) {
        if (root == nullptr)
            return -1;
        if (mem.find(root) != mem.end())
            return mem[root];
        else {
            int h = 1 + max(height(root->left), height(root->right));
            mem[root] = h;
            return h;
        }
    }
};