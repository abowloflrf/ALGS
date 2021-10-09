#include <queue>
#include <stack>
#include <vector>

using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// 非递归前序遍历，额外用一个 stack
vector<int> preOrderNoRecursive(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *node = root;
    while (node != nullptr || !s.empty()) {
        while (node != nullptr) {
            result.push_back(node->val);
            s.push(node);
            node = node->left;
        }
        node = s.top();
        s.pop();
        node = node->right;
    }
    return result;
}