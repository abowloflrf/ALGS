/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (65.16%)
 * Likes:    520
 * Dislikes: 0
 * Total Accepted:    130.3K
 * Total Submissions: 199.9K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to
 * bottom.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,5,null,4]
 * Output: [1,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,null,3]
 * Output: [1,3]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
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
 */
#include <queue>
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
    vector<int> rightSideView(TreeNode *root) {
        if (!root)
            return {};
        deque<TreeNode *> Q;
        vector<int> ans;
        Q.push_back(root);
        while (!Q.empty()) {
            int size = Q.size();
            ans.push_back(Q.back()->val);
            for (int i = 0; i < size; i++) {
                auto node = Q.front();
                if (node->left)
                    Q.push_back(node->left);
                if (node->right)
                    Q.push_back(node->right);
                Q.pop_front();
            }
        }
        return ans;
    }
};
// @lc code=end
