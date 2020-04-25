/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (53.96%)
 * Likes:    1989
 * Dislikes: 54
 * Total Accepted:    325.2K
 * Total Submissions: 572.2K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Example 1:
 *
 *
 * Input: root = [3,1,4,null,2], k = 1
 * ⁠  3
 * ⁠ / \
 * ⁠1   4
 * ⁠ \
 * 2
 * Output: 1
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * ⁠      5
 * ⁠     / \
 * ⁠    3   6
 * ⁠   / \
 * ⁠  2   4
 * ⁠ /
 * ⁠1
 * Output: 3
 *
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest
 * routine?
 *
 */

#include "utils/tree.h"
#include <stack>
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
    int kthSmallest(TreeNode *root, int k) {
        inorder(root);
        return v[k - 1];
    }

  private:
    vector<int> v;
    void inorder(TreeNode *node) {
        if (node != nullptr) {
            inorder(node->left);
            v.push_back(node->val);
            inorder(node->right);
        }
    }
};
// @lc code=end

// 非递归方式遍历
class Solution2 {
  public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> s;
        int n = 0; //计数，到k个时break即可
        while (true) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            TreeNode *node = s.top();
            s.pop();
            if (++n == k) {
                return node->val;
            }
            root = node->right;
        }
        return -1;
    }
};