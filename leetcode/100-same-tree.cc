
class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) return p == nullptr && q == nullptr;
        bool isSame = p->val == q->val;
        return isSame && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};