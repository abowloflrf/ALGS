#include <iostream>
/**
 * 二叉搜索树的结构
 */
class TreeNode {
   public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
   public:
    //从二叉搜索树中以递归的形式插入一个节点
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (root == nullptr) {
            return node;
        }
        if (node->val < root->val) {
            root->left = insertNode(root->left, node);
        } else {
            root->right = insertNode(root->right, node);
        }
        return root;
    }

    //非递归形式插入节点
    TreeNode* insertNode2(TreeNode* root, TreeNode* node) {
        if (root == nullptr) {
            return node;
        }
        TreeNode* parent = nullptr;
        TreeNode* p = root;
        bool left = true;
        while (p) {
            parent = p;
            if (p->val <= node->val) {
                p = p->right;
                left = false;
            } else {
                p = p->left;
                left = true;
            }
        }
        if (left) {
            parent->left = node;
        } else {
            parent->right = node;
        }
        return root;
    }
};