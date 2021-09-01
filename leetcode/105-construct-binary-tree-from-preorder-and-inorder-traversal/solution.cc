/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.39%)
 * Likes:    1182
 * Dislikes: 0
 * Total Accepted:    238.2K
 * Total Submissions: 338.4K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same
 * tree, construct and return the binary tree.
 *
 *
 * Example 1:
 *
 *
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 *
 *
 * Example 2:
 *
 *
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
 *
 *
 */

#include <vector>
using namespace std;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // 前序遍历特性：首位为树的根节点，然后分别是左子树节点、右子树节点
        // 中序遍历特性：左子树节点、根节点、右子树节点
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int startPre, int endPre, int startIn, int endIn) {
        if (startPre > endPre || startIn > endIn)
            return nullptr;
        int rootVal = preorder[startPre];
        TreeNode *root = new TreeNode(rootVal);

        // inorder 中找到根节点 rootval，得到新的左右子树以及长度
        int inorderRootIdx = startIn;
        int leftSize = 0;
        for (int i = startIn; i <= endIn; i++) {
            if (inorder[i] == rootVal) {
                inorderRootIdx = i;
                break;
            }
            leftSize++;
        }
        root->left = build(preorder, inorder, startPre + 1, startPre + leftSize, startIn, startIn + leftSize - 1);
        root->right = build(preorder, inorder, startPre + leftSize + 1, endPre, startIn + leftSize + 1, endIn);
        return root;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    /* code */
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    return 0;
}
