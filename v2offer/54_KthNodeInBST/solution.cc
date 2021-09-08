
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int kthLargest(TreeNode *root, int k) {
        // 非递归中序遍历
        // 注意，倒序遍历，即先走右节点
        stack<TreeNode *> s;
        int idx = 0;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->right;
            }
            root = s.top();
            // dala, here we go
            if (++idx == k) {
                return root->val;
            }
            s.pop();
            root = root->left;
        }
        return -1;
    }
};