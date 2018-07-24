//
// Created by ruofeng on 2018/7/24.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int s) : val(s), left(nullptr), right(nullptr) {}
};

TreeNode *getKthNode(int k, TreeNode *tree) {
    vector<TreeNode *> seq;
    stack<TreeNode *> S;
    TreeNode *node = tree;
    //非递归中序遍历
    while (node != nullptr || !S.empty()) {
        while (node != nullptr) {
            S.push(node);
            node = node->left;
        }
        node = S.top();
        S.pop();
        seq.push_back(node);
        node = node->right;
    }
    return seq[k - 1];

}

int main() {
    TreeNode *tree = new TreeNode(5);
    tree->left = new TreeNode(3);
    tree->right = new TreeNode(7);
    tree->left->left = new TreeNode(2);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(8);

    TreeNode *targetNode = getKthNode(4, tree);
    cout << targetNode->val << endl;
    return 0;
}