/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (43.71%)
 * Likes:    1680
 * Dislikes: 87
 * Total Accepted:    321.1K
 * Total Submissions: 701.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 *
 * return its zigzag level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 *
 *
 */
#include "utils/tree.h"
#include <deque>
#include <list>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};
        deque<TreeNode *> Q;
        vector<vector<int>> res;
        bool flag = true;
        Q.push_back(root);
        while (!Q.empty()) {
            vector<int> level;
            int qsize = Q.size();
            if (flag) {
                for (int i = 0; i < qsize; i++) {
                    TreeNode *node = Q.front();
                    Q.pop_front();

                    if (node->left != nullptr)
                        Q.push_back(node->left);
                    if (node->right != nullptr)
                        Q.push_back(node->right);
                    level.push_back(node->val);
                }
            } else {
                for (int i = 0; i < qsize; i++) {
                    TreeNode *node = Q.back();
                    Q.pop_back();

                    if (node->right != nullptr)
                        Q.push_front(node->right);
                    if (node->left != nullptr)
                        Q.push_front(node->left);
                    level.push_back(node->val);
                }
            }
            res.push_back(level);
            flag = !flag;
        }
        return res;
    }
};
// @lc code=end
