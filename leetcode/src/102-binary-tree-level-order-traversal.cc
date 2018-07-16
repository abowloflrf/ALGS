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
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty()) {
            int num = Q.size();
            res.push_back({});
            for (int i = 0; i < num; i++) {
                TreeNode *node = Q.front();
                res.back().push_back(node->val);
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                Q.pop();
            }
        }
        return res;
    }
};
int main() {}