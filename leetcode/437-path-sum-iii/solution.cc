/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.cn/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (48.95%)
 * Likes:    1766
 * Dislikes: 0
 * Total Accepted:    260.6K
 * Total Submissions: 532.4K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * Given the root of a binary tree and an integer targetSum, return the number
 * of paths where the sum of the values along the path equals targetSum.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards (i.e., traveling only from parent nodes to child nodes).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * Output: 3
 * Explanation: The paths that sum to 8 are shown.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 1000].
 * -10^9 <= Node.val <= 10^9
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
    int pathSum(TreeNode *root, int targetSum) { return dfs(root, targetSum); }

    int dfs(TreeNode *node, int sum) {
        if (!node) {
            return 0;
        }
        int ans = pathFromRoot(node, sum);
        return ans + dfs(node->left, sum) + dfs(node->right, sum);
    }
    // 以 node 开始，和胃 target sum 的 path 数量
    int pathFromRoot(TreeNode *node, long long targetSum) {
        if (!node) {
            return 0;
        }
        int ans = 0;
        if (node->val == targetSum) {
            ans++;
        }
        return ans + pathFromRoot(node->left, targetSum - node->val) + pathFromRoot(node->right, targetSum - node->val);
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->left->left = new TreeNode(3);
    tree->left->left->left = new TreeNode(4);
    tree->left->left->left->left = new TreeNode(5);
    Solution s;
    int a = s.pathSum(tree, 3);
    return 0;
}
