#include <iostream>
#include <queue>
using namespace std;

class BinaryTreeNode {
   public:
    int val;
    BinaryTreeNode *left, *right;
    BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printTree(BinaryTreeNode *tree) {
    queue<BinaryTreeNode *> Q;
    Q.push(tree);
    while (!Q.empty()) {
        int num = Q.size();
        for (int i = 0; i < num; i++) {
            BinaryTreeNode *node = Q.front();
            cout << node->val << "-";
            if (node->left) Q.push(node->left);
            if (node->right) Q.push(node->right);
            Q.pop();
        }
    }
}

int main() {
    BinaryTreeNode *treeA = new BinaryTreeNode(8);
    treeA->left = new BinaryTreeNode(8);
    treeA->right = new BinaryTreeNode(7);
    treeA->left->left = new BinaryTreeNode(9);
    treeA->left->right = new BinaryTreeNode(2);
    treeA->left->right->left = new BinaryTreeNode(4);
    treeA->left->right->right = new BinaryTreeNode(7);
    printTree(treeA);
    return 0;
}