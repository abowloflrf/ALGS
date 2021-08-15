/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (75.58%)
 * Likes:    1061
 * Dislikes: 0
 * Total Accepted:    515.5K
 * Total Submissions: 682K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 * Example 4:
 *
 *
 * Input: root = [1,2]
 * Output: [2,1]
 *
 *
 * Example 5:
 *
 *
 * Input: root = [1,null,2]
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */
#include <stack>
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

class Solution {
  public:
    // 递归方式
    vector<int> inorderTraversal(TreeNode *root) {
        inorder(root);
        return ans;
    }
    // 基于栈的非递归方式
    vector<int> inorderTraversal2(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> ans;

        while (root != nullptr || !s.empty()) {
            // 只要有左节点就直接 push
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            // 左节点已找到尽头，push 中间节点到结果
            TreeNode *tmp = s.top();
            ans.push_back(s.top()->val);
            s.pop();
            // 然后继续从右节点寻找
            root = tmp->right;
        }

        return ans;
    }

  private:
    vector<int> ans;
    void inorder(TreeNode *node) {
        if (!node) {
            return;
        }
        inorder(node->left);
        ans.push_back(node->val);
        inorder(node->right);
    };
};
// @lc code=end
