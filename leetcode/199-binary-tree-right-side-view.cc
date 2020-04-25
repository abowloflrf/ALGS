/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (50.06%)
 * Likes:    1850
 * Dislikes: 106
 * Total Accepted:    253.2K
 * Total Submissions: 483.5K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * Example:
 *
 *
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 *
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 *
 */
#include "utils/tree.h"
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr)
            return {};
        deque<TreeNode *> Q;
        vector<int> rightSide;
        Q.push_front(root);
        while (!Q.empty()) {
            int levelSize = Q.size();
            rightSide.push_back(Q.back()->val);
            for (int i = 0; i < levelSize; i++) {
                TreeNode *tmpNode = Q.front();
                if (tmpNode->left != nullptr)
                    Q.push_back(tmpNode->left);
                if (tmpNode->right != nullptr)
                    Q.push_back(tmpNode->right);
                Q.pop_front();
            }
        }
        return rightSide;
    }
};
// @lc code=end
