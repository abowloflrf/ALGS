/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (67.96%)
 * Likes:    562
 * Dislikes: 0
 * Total Accepted:    133.8K
 * Total Submissions: 196.9K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given the root of a binary tree, return all root-to-leaf paths in any
 * order.
 *
 * A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,5]
 * Output: ["1->2->5","1->3"]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: ["1"]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 100].
 * -100 <= Node.val <= 100
 *
 *
 */
#include <string>
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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root) {
            return {};
        }
        string path = "";
        dfs(path, root);
        return res;
    }

  private:
    void dfs(string path, TreeNode *root) {
        if (!root) {
            return;
        }
        if (path == "")
            path = to_string(root->val);
        else {
            path += "->" + to_string(root->val);
        }
        // 到叶子节点，push 到结果
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }
        dfs(path, root->left);
        dfs(path, root->right);
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    Solution s;
    TreeNode *t = new TreeNode(1);
    auto ans = s.binaryTreePaths(t);
    return 0;
}
