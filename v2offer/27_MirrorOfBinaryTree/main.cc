#include <iostream>
using namespace std;

class BinaryTreeNode {
   public:
    int val;
    BinaryTreeNode *left, *right;
    BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void mirror(BinaryTreeNode *tree) {
    if (tree == nullptr) return;
    //交换左右节点
    BinaryTreeNode *temp = tree->left;
    tree->left = tree->right;
    tree->right = temp;
    mirror(tree->left);
    mirror(tree->right);
}

int main() {
    BinaryTreeNode *treeA = new BinaryTreeNode(3);
    treeA->left = new BinaryTreeNode(4);
    treeA->right = new BinaryTreeNode(5);
    treeA->left->left = new BinaryTreeNode(1);
    treeA->left->right = new BinaryTreeNode(2);
    treeA->left->left->left = new BinaryTreeNode(0);
    mirror(treeA);
    return 0;
}