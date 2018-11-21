#include <iostream>

using namespace std;

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
   private:
    int currentMinDepth;

   public:
    /**
     * @param root: The root of binary tree
     * @return: An integer
     */
    Solution() { this->currentMinDepth = 0; }
    void getMinDepth(TreeNode *node, int currentDepth) {
        if (node->left == nullptr && node->right == nullptr) {
            this->currentMinDepth = currentDepth;
            return;
        }
        if (this->currentMinDepth != 0 && currentDepth >= this->currentMinDepth)
            return;
        if (node->left) this->getMinDepth(node->left, currentDepth + 1);
        if (node->right) this->getMinDepth(node->right, currentDepth + 1);
    }
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        this->getMinDepth(root, 1);
        return this->currentMinDepth;
    }
};