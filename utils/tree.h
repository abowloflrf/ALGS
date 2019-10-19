#ifndef ALGS_TREE_H
#define ALGS_TREE_H

// TreeNode 树节点
class TreeNode {
  public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

#endif // ALGS_TREE_H