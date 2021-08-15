/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (69.77%)
 * Likes:    960
 * Dislikes: 0
 * Total Accepted:    94.6K
 * Total Submissions: 135.6K
 * Testcase Example:  '3'
 *
 * Given an integer n, return all the structurally unique BST's (binary search
 * trees), which has exactly n nodes of unique values from 1 to n. Return the
 * answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output:
 * [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 8
 *
 *
 */
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
    vector<TreeNode *> generateTrees(int n) { return helper(1, n); }

  private:
    vector<TreeNode *> helper(int start, int end) {
        if (start > end)
            // 这里很关键，必须是有一个元素且元素为null的vector
            // 否则下面遇到 start = end 时无法拼接只有一个root节点的树
            return {nullptr};
        vector<TreeNode *> trees;
        // 对于所有可能的根节点，递归一遍所有可能的左子树和右子树情况
        // 两种情况的组合 m*n 与 根节点 i，加入到结果中
        for (int i = start; i <= end; i++) {
            auto left = helper(start, i - 1);
            auto right = helper(i + 1, end);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode *n = new TreeNode(i);
                    n->left = l;
                    n->right = r;
                    trees.push_back(n);
                }
            }
        }
        return trees;
    }
};
// @lc code=end
