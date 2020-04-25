/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (64.12%)
 * Likes:    2026
 * Dislikes: 66
 * Total Accepted:    707.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
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
 * return its depth = 3.
 *
 */

#include "./utils/tree.h"
#include <deque>
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
// 自底向上方式
class Solution {
  public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        return max(leftHeight, rightHeight) + 1;
        return 1;
    }
};
// @lc code=end

// 自顶向下方式
class Solution2 {
  public:
    int maximum_depth(TreeNode *root, int depth) {
        if (!root) {
            return depth - 1;
        }
        return max(maximum_depth(root->left, depth + 1), maximum_depth(root->right, depth + 1));
    }
    int maxDepth(TreeNode *root) { return maximum_depth(root, 1); }
};

// 非递归方式 BFS 层次遍历
class Solution3 {
  public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        deque<TreeNode *> Q;
        Q.push_back(root);
        int ans = 0;
        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = Q.front();
                Q.pop_front();
                if (node->left != nullptr)
                    Q.push_back(node->left);
                if (node->right != nullptr)
                    Q.push_back(node->right);
            }
            ans++;
        }
        return ans;
    }
};