/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (45.68%)
 * Likes:    3314
 * Dislikes: 81
 * Total Accepted:    559.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 *
 * But the following [1,2,2,null,3,null,3] is not:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 *
 */

#include "./utils/tree.h"
#include <bits/stdc++.h>

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

// 递归方式
class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        return isSymmetricTree(root->left, root->right);
    }
    bool isSymmetricTree(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return isSymmetricTree(left->right, right->left) && isSymmetricTree(left->left, right->right);
    }
};
// @lc code=end

// 非递归方式，使用队列
class Solution2 {
  public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            // 队列中每次判断一对TreeNode
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();
            if (!t1 && !t2) //左右节点均为空指针，通过
                continue;
            if (!t1 || !t2) //左右节点有一个为空指针，另一个非空，此时已经不对称了
                return false;
            if (t1->val != t2->val) //左右节点两值必须
                return false;
                
            // 需要注意次入队顺序，因为需要是镜像，两对关系应如下
            // <left->left,right->right>
            // <left->right,right->left>
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};