#include <stack>
#include <vector>
using namespace std;

class Node {
  public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
  public:
    Node *treeToDoublyList(Node *root) {
        if (!root)
            return nullptr;
        // 中序遍历存入 list
        // 根据 list 构造循环双向链表
        vector<Node *> nodeList;
        inorder(root, nodeList);
        if (nodeList.size() == 1) {
            nodeList[0]->left = nodeList[0];
            nodeList[0]->right = nodeList[0];
            return nodeList[0];
        }
        // 构造头尾
        nodeList[0]->left = nodeList.back();
        nodeList[0]->right = nodeList[1];
        nodeList.back()->left = nodeList[nodeList.size() - 2];
        nodeList.back()->right = nodeList.front();
        // 构造中间
        for (int i = 1; i < nodeList.size() - 1; i++) {
            nodeList[i]->left = nodeList[i - 1];
            nodeList[i]->right = nodeList[i + 1];
        }
        return nodeList.front();
    }

  private:
    void inorder(Node *root, vector<Node *> &list) {

        // if (!root)
        //     return;
        // // 递归中序遍历
        // inorder(root->left, list);
        // list.push_back(root);
        // inorder(root->right, list);

        // 顺便复习一遍非递归的中序遍历
        stack<Node *> stk;
        Node *node = root;
        while (node != nullptr || !stk.empty()) {
            while (node) {
                stk.push(node);
                node = node->left;
            }
            // 左边走到头就把最后一个向左的节点 push
            // 并把它父节点的右子节点加入重新判断
            node = stk.top();
            list.push_back(node);
            stk.pop();
            node = node->right;
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    Node *head = new Node(1);
    auto a = s.treeToDoublyList(head);
    return 0;
}
