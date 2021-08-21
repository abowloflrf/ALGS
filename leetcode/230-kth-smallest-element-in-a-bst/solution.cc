/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (73.94%)
 * Likes:    429
 * Dislikes: 0
 * Total Accepted:    128.8K
 * Total Submissions: 174K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given the root of a binary search tree, and an integer k, return the k^th
 * (1-indexed) smallest element in the tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is n.
 * 1 <= k <= n <= 10^4
 * 0 <= Node.val <= 10^4
 *
 *
 *
 * Follow up: If the BST is modified often (i.e., we can do insert and delete
 * operations) and you need to find the kth smallest frequently, how would you
 * optimize?
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> s;
        int n = 0;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            // 剪枝
            if (n == k - 1) {
                return root->val;
            }
            n++;
            root = root->right;
        }
        return -1;
    }
};
// @lc code=end
