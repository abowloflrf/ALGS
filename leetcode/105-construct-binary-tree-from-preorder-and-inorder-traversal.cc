/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (43.76%)
 * Likes:    2696
 * Dislikes: 78
 * Total Accepted:    310.6K
 * Total Submissions: 674.4K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 *
 * Return the following binary tree:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 */
#include "utils/tree.h"
#include <vector>
using namespace std;
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
        if (preorder.empty() || inorder.empty())
            return nullptr;
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

  private:
    TreeNode *build(vector<int> &preorder, int pstart, int pend, vector<int> &inorder, int istart, int iend) {
        // 新建根节点（前序遍历的第一个元素）
        TreeNode *root = new TreeNode(preorder[pstart]);

        // 在中序遍历中找到跟节点的位置，则左边部分为左子树，右边部分为右子树
        int mid;
        for (int i = istart; i <= iend; i++) {
            if (inorder[i] == preorder[pstart]) {
                mid = i;
                break;
            }
        }
        int leftSize = mid - istart;
        int rightSize = iend - mid;
        // 递归构造左子树
        if (leftSize > 0)
            root->left = build(preorder, pstart + 1, pstart + 1 + leftSize, inorder, istart, mid - 1);
        // 递归构造右子树
        if (rightSize > 0)
            root->right = build(preorder, pstart + 1 + leftSize, pend, inorder, mid + 1, iend);

        return root;
    }
};
// @lc code=end
