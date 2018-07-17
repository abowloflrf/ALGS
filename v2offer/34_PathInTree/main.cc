#include <iostream>
#include <vector>

using namespace std;

class BinaryTreeNode {
   public:
    int val;
    BinaryTreeNode *left, *right;
    BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void findPathCore(BinaryTreeNode* root, int target, vector<int>& currentPath,
                  int currentSum) {
    currentSum += root->val;
    currentPath.push_back(root->val);

    bool isLeaf = root->left == nullptr && root->right == nullptr;
    //找到一条路径
    if (currentSum == target && isLeaf) {
        for (auto item : currentPath) cout << item << "-";
        cout << endl;
    }
    //不是叶子节点则向下遍历
    if (!isLeaf) {
        if (root->left != nullptr)
            findPathCore(root->left, target, currentPath, currentSum);
        if (root->right != nullptr)
            findPathCore(root->right, target, currentPath, currentSum);
    }
    //回溯
    currentPath.pop_back();
}
void findPath(BinaryTreeNode* tree, int target) {
    if (tree == nullptr) return;
    vector<int> path;
    int currentSum = 0;
    findPathCore(tree, target, path, currentSum);
}

int main() {
    BinaryTreeNode* treeA = new BinaryTreeNode(3);
    treeA->left = new BinaryTreeNode(4);
    treeA->right = new BinaryTreeNode(5);
    treeA->left->left = new BinaryTreeNode(1);
    treeA->left->right = new BinaryTreeNode(2);
    treeA->left->left->left = new BinaryTreeNode(0);
    findPath(treeA, 8);
    return 0;
}