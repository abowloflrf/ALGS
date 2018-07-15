class TreeNode {
   public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    /**
     * @param s: the s' root
     * @param t: the t' root
     * @return: whether tree t has exactly the same structure and node values
     * with a subtree of s
     */
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (s == nullptr) return true ? t == nullptr : false;
        bool result = false;
        if (s->val == t->val) result = isSameTree(s, t);
        if (!result) result = isSubtree(s->left, t);
        if (!result) result = isSubtree(s->right, t);
        return result;
    }

   private:
    bool isSameTree(TreeNode *treeA, TreeNode *treeB) {
        if (treeA == nullptr || treeB == nullptr)
            return treeA == nullptr && treeB == nullptr;
        bool isSame = treeA->val == treeB->val;
        return isSame && isSameTree(treeA->left, treeB->left) &&
               isSameTree(treeA->right, treeB->right);
    }
};