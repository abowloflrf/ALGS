#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/**
 * Definition of TreeNode:
 */
class TreeNode {
   public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
   public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        //新建一个队列保存数的节点，并先将根节点保存
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;  //保存每一层次的节点的值
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                level.push_back(node->val);
                q.pop();
                //依次将上一层的节点的左右节点（若存在），加入到队列中
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }
};