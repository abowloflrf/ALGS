/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (36.06%)
 * Likes:    1208
 * Dislikes: 643
 * Total Accepted:    391.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * return its minimum depth = 2.
 *
 */
#include "utils/tree.h"
#include <queue>
using namespace std;
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
    int minDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> Q;
        Q.push(root);
        int minLevel = 0;
        while (!Q.empty()) {
            int levelSize = Q.size();
            minLevel++;
            for (int i = 0; i < levelSize; i++) {
                TreeNode *t = Q.front();
                Q.pop();
                if (t->left == nullptr && t->right == nullptr) {
                    return minLevel;
                }
                if (t->left != nullptr)
                    Q.push(t->left);
                if (t->right != nullptr)
                    Q.push(t->right);
            }
        }
        return minLevel;
    }
};
// @lc code=end
