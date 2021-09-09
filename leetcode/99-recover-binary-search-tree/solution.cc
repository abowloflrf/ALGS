/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Medium (61.58%)
 * Likes:    550
 * Dislikes: 0
 * Total Accepted:    69K
 * Total Submissions: 112.7K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * You are given the root of a binary search tree (BST), where the values of
 * exactly two nodes of the tree were swapped by mistake. Recover the tree
 * without changing its structure.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,3,null,null,2]
 * Output: [3,1,null,null,2]
 * Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3
 * makes the BST valid.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,1,4,null,null,2]
 * Output: [2,1,4,null,null,3]
 * Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2
 * and 3 makes the BST valid.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 1000].
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 *
 * Follow up: A solution using O(n) space is pretty straight-forward. Could you
 * devise a constant O(1) space solution?
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
    void recoverTree(TreeNode *root) {
        // 中序遍历
        stack<TreeNode *> S;
        TreeNode *node = root;
        TreeNode *pre = nullptr;
        TreeNode *a = nullptr, *b = nullptr;
        while (!S.empty() || node) {
            while (node) {
                S.push(node);
                node = node->left;
            }
            node = S.top();
            S.pop();
            if (pre && pre->val > node->val) {
                a = node;
                if (!b) {
                    b = pre;
                } else {
                    // 找到第二个，直接打断即可
                    break;
                }
            }
            pre = node;
            node = node->right;
        }
        // 交换
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
};
// @lc code=end
