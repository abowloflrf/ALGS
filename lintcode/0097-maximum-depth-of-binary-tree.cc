
class TreeNode {
   public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

class Solution {
   private:
    int depth = 0;

   public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        this->stepInto(root, 1);
        return this->depth;
    }
    void stepInto(TreeNode *root, int currentDepth) {
        if (root->left != nullptr) {
            this->stepInto(root->left, currentDepth + 1);
        }
        if (root->right != nullptr) {
            this->stepInto(root->right, currentDepth + 1);
        }
        if (currentDepth > this->depth) this->depth = currentDepth;
    }
};