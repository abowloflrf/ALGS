#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归方式
// Time: O(n)
// Space: O(n)
class Solution1 {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr)
            return levels;
        helper(root, 0);
        return levels;
    }
    void helper(TreeNode *root, int level) {
        // 开始当前层级，并插入次节点的value
        if (levels.size() == level)
            levels.push_back({});
        levels[level].push_back(root->val);
        // 对下一层递归调用
        if (root->left)
            helper(root->left, level + 1);
        if (root->right)
            helper(root->right, level + 1);
    }
    vector<vector<int>> levels;
};

// 非递归方式，使用辅助的队列实现
// Time: O(n)
// Space: O(n)
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> q;
        // 队列中加入第一层的节点
        q.push(root);
        while (!q.empty()) {
            res.push_back({});
            int levelWidth = q.size(); // 注意不能将这里的q.size()放到下面的for循环中，因为循环中q的大小在变换
            // 每次for循环开始前，q中依次存放的是这一层的所有TreeNode
            for (int i = 0; i < levelWidth; i++) {
                // 取队首节点并加入到结果的这一层中
                TreeNode *node = q.front();
                q.pop();
                res.back().push_back(node->val);
                // 依次再将下一层的左右节加入到队尾，由于for中保证循环了levelWidth次数
                // 因此此次循环中不会处理到下一层的队列的节点数据
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return res;
    }
};
