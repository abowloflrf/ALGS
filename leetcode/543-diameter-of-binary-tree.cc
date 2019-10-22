/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (47.60%)
 * Likes:    1763
 * Dislikes: 110
 * Total Accepted:    168.5K
 * Total Submissions: 353.9K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 *
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 *
 *
 *
 * Example:
 * Given a binary tree
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \
 * ⁠     4   5
 *
 *
 *
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 *
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "utils/tree.h"
#include <iostream>
using namespace std;

// @lc code=start
class Solution {

  public:
    int diameterOfBinaryTree(TreeNode *root) {
        ans = 0;
        depth(root);
        return ans;
    }

  private:
    // ans 储存结果
    int ans;
    // depth 计算root阶段为根节点的二叉树的深度
    int depth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int L = this->depth(root->left);  // L为左子树深度
        int R = this->depth(root->right); // R为右子数深度
        // 递归计算树的深度时，找到左右子树深度最大值和
        this->ans = max(this->ans, L + R);
        // root深度为左右字数最深之一 +1
        return max(L, R) + 1;
    }
};
// @lc code=end
