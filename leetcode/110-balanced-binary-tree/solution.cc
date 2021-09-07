/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (56.27%)
 * Likes:    761
 * Dislikes: 0
 * Total Accepted:    248.6K
 * Total Submissions: 441.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as:
 *
 *
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -10^4 <= Node.val <= 10^4
 *
 *
 */
#include <algorithm>
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
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        return height(root) != -1;
    }

  private:
    // 返回树的高度，若左右不平衡，直接返回-1
    int height(TreeNode *root) {
        if (!root)
            return 0;
        int left = height(root->left);
        if (left == -1)
            return -1;
        int right = height(root->right);
        if (right == -1)
            return -1;
        if (abs(left - right) <= 1)
            return max(left, right) + 1;
        return -1;
    }
};
// @lc code=end

// 较差解法，会大量重复计算
class Solution2 {
  public:
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        return (abs(height(root->left) - height(root->right)) <= 1) && isBalanced(root->left) &&
               isBalanced(root->right);
    }

  private:
    int height(TreeNode *root) {
        if (!root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};