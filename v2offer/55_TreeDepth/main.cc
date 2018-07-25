//
// Created by ruofeng on 2018/7/24.
//


#include <iostream>

using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int s) : val(s), left(nullptr), right(nullptr) {}
};

int getDepth(TreeNode *tree, int depth) {
    if (tree == nullptr)
        return depth - 1;
    return max(getDepth(tree->left, dep/th + 1), getDepth(tree->right, depth + 1));
}

int main() {
    TreeNode *tree = new TreeNode(5);
    tree->left = new TreeNode(3);
    tree->right = new TreeNode(7);
    tree->left->left = new TreeNode(2);
    tree->left->right = new TreeNode(4);
    tree->left->left->left = new TreeNode(100);
    cout << getDepth(tree, 1) << endl;
    return 0;
}
