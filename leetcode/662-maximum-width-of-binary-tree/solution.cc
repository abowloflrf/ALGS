/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 *
 * https://leetcode-cn.com/problems/maximum-width-of-binary-tree/description/
 *
 * algorithms
 * Medium (40.54%)
 * Likes:    245
 * Dislikes: 0
 * Total Accepted:    26.3K
 * Total Submissions: 64.9K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * Given the root of a binary tree, return the maximum width of the given
 * tree.
 *
 * The maximum width of a tree is the maximum width among all levels.
 *
 * The width of one level is defined as the length between the end-nodes (the
 * leftmost and rightmost non-null nodes), where the null nodes between the
 * end-nodes are also counted into the length calculation.
 *
 * It is guaranteed that the answer will in the range of 32-bit signed
 * integer.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,3,2,5,3,null,9]
 * Output: 4
 * Explanation: The maximum width existing in the third level with the length 4
 * (5,3,null,9).
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,3,null,5,3]
 * Output: 2
 * Explanation: The maximum width existing in the third level with the length 2
 * (5,3).
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1,3,2,5]
 * Output: 2
 * Explanation: The maximum width existing in the second level with the length
 * 2 (3,2).
 *
 *
 * Example 4:
 *
 *
 * Input: root = [1,3,2,5,null,null,9,6,null,null,7]
 * Output: 8
 * Explanation: The maximum width existing in the fourth level with the length
 * 8 (6,null,null,null,null,null,null,7).
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 3000].
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

struct NodeWithID {
    /* data */
};

class Solution {
  public:
    int widthOfBinaryTree(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int maxWith = 0;
        queue<TreeNode *> Q;
        root->val = 0;
        Q.push(root);
        while (!Q.empty()) {
            int count = Q.size();
            int levelWith = Q.back()->val - Q.front()->val + 1;
            if (levelWith > maxWith) {
                maxWith = levelWith;
            }
            int offset = Q.front()->val;
            // 判断下一层
            for (int i = 0; i < count; i++) {
                TreeNode *node = Q.front();
                // 避免溢出，每层第一个都按0计算
                node->val = node->val - offset;
                Q.pop();
                if (node->left) {
                    node->left->val = node->val * 2;
                    Q.push(node->left);
                }
                if (node->right) {
                    node->right->val = node->val * 2 + 1;
                    Q.push(node->right);
                }
            }
        }
        return maxWith;
    }
};
// @lc code=end
