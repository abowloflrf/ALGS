/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 *
 * https://leetcode-cn.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (47.32%)
 * Likes:    557
 * Dislikes: 0
 * Total Accepted:    84.4K
 * Total Submissions: 178.3K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * Given the roots of two binary trees root and subRoot, return true if there
 * is a subtree of root with the same structure and node values of subRoot and
 * false otherwise.
 *
 * A subtree of a binary tree tree is a tree that consists of a node in tree
 * and all of this node's descendants. The tree tree could also be considered
 * as a subtree of itself.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,4,5,1,2], subRoot = [4,1,2]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the root tree is in the range [1, 2000].
 * The number of nodes in the subRoot tree is in the range [1, 1000].
 * -10^4 <= root.val <= 10^4
 * -10^4 <= subRoot.val <= 10^4
 *
 *
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot)
            return true;
        if (!root)
            return false;
        // DFS
        bool result = (root->val == subRoot->val) && isSametree(root, subRoot);
        if (!result) {
            // 左右子树递归判断
            result = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        return result;
    }

  private:
    bool isSametree(TreeNode *rootA, TreeNode *rootB) {
        // 类似判断树是否镜像
        if (!rootA && !rootB)
            return true;
        if (!rootA || !rootB)
            return false;
        return (rootA->val == rootB->val) && isSametree(rootA->left, rootB->left) &&
               isSametree(rootA->right, rootB->right);
    }
};
// @lc code=end
