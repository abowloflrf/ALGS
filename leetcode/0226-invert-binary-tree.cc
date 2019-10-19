// LeetCode Link: https://leetcode.com/problems/invert-binary-tree/

#include "utils/tree.h"
#include <queue>

using namespace std;

class Solution {
  public:
    // 递归算法
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr)
            return root;

        // 交换左右节点
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        // 递归对左右节点进行交换
        this->invertTree(root->left);
        this->invertTree(root->right);
        return root;
    }

    TreeNode *invertTree2(TreeNode *root) {
        if (root == nullptr)
            return root;
    }
};