/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (52.56%)
 * Likes:    640
 * Dislikes: 0
 * Total Accepted:    248.3K
 * Total Submissions: 472.4K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given the root of a binary tree and an integer targetSum, return true if the
 * tree has a root-to-leaf path such that adding up all the values along the
 * path equals targetSum.
 *
 * A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3], targetSum = 5
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1,2], targetSum = 0
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
 *
 *
 */
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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }

        // 注意题意是到叶子节点，即 root 的左右节点均需要是空
        if (root->val == targetSum && root->left == nullptr && root->right == nullptr)
            return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
// @lc code=end
