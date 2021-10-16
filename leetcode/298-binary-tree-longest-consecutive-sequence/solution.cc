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
class Solution {
  public:
    int longestConsecutive(TreeNode *root) {
        dfs(root, 0);
        return ans;
    }

  private:
    int ans = 0;
    void dfs(TreeNode *root, int current) {
        if (!root)
            return;
        int currentMax = current + 1;
        if (currentMax > ans)
            ans = currentMax;
        if (!root->left && !root->right) {
            return;
        }

        if (root->left) {
            if (root->left->val == root->val + 1) {
                dfs(root->left, current + 1);
            } else {
                dfs(root->left, 0);
            }
        }
        if (root->right) {
            if (root->right->val == root->val + 1) {
                dfs(root->right, current + 1);
            } else {
                dfs(root->right, 0);
            }
        }
    }
};