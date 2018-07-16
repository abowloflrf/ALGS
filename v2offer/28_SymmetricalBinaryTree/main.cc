#include <iostream>
using namespace std;

class BinaryTreeNode {
   public:
    int val;
    BinaryTreeNode *left, *right;
    BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSymmetrical(BinaryTreeNode *treeLeft, BinaryTreeNode *treeRight) {
    if (treeLeft == nullptr && treeRight == nullptr) return true;
    if (treeLeft == nullptr || treeRight == nullptr) return false;
    if (treeLeft->val != treeRight->val) return false;
    return isSymmetrical(treeLeft->left, treeRight->right) &&
           isSymmetrical(treeLeft->right, treeRight->left);
}

bool isSymmetrical(BinaryTreeNode *tree) { return isSymmetrical(tree, tree); }

int main() {
    BinaryTreeNode *treeA = new BinaryTreeNode(8);
    treeA->left = new BinaryTreeNode(8);
    treeA->right = new BinaryTreeNode(8);
    treeA->left->left = new BinaryTreeNode(8);
    treeA->left->right = new BinaryTreeNode(8);
    treeA->right->left = new BinaryTreeNode(8);
    // treeA->right->right = new BinaryTreeNode(5);
    bool result = isSymmetrical(treeA);
    cout << result << endl;
    return 0;
}