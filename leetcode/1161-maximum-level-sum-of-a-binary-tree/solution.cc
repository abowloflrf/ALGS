/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 *
 * https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (65.64%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    43.6K
 * Total Submissions: 66.4K
 * Testcase Example:  '[1,7,0,7,-8,null,null]'
 *
 * Given the root of a binary tree, the level of its root is 1, the level of
 * its children is 2, and so on.
 *
 * Return the smallest level x such that the sum of all the values of nodes at
 * level x is maximal.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,7,0,7,-8,null,null]
 * Output: 2
 * Explanation:
 * Level 1 sum = 1.
 * Level 2 sum = 7 + 0 = 7.
 * Level 3 sum = 7 + -8 = -1.
 * So we return the level with the maximum sum which is level 2.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
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
#include <climits>
#include <deque>
#include <vector>
using namespace std;
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
    int levelNumber = 0;
    int maxSum = INT_MIN;
    int maxLevelSum(TreeNode *root) {
        if (!root)
            return 0;
        deque<TreeNode *> level = {root};
        int currentLevel = 1;
        while (!level.empty()) {
            int currentSum = 0;
            int size = level.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = level.front();
                currentSum += node->val;
                if (node->left) {
                    level.push_back(node->left);
                }
                if (node->right)
                    level.push_back(node->right);
                level.pop_front();
            }
            if (currentSum > maxSum) {
                maxSum = currentSum;
                levelNumber = currentLevel;
            }
            // 下一层
            currentLevel++;
        }
        return levelNumber;
    }
};
// @lc code=end
