//
// Created by ruofeng on 2018/7/17.
//
#include <iostream>
using namespace std;

//结果中将树的节点作为双向链表的节点，left指向前面，right指向后面
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

class Solution {
  public:
    TreeNode *convertTree(TreeNode *tree) {
        inOrder(tree);
        return head;
    }
  private:
    TreeNode *prev = nullptr;
    TreeNode *head = nullptr;
    void inOrder(TreeNode *root) {
        if (root == nullptr)
            return;

        inOrder(root->left);

        root->left = prev;
        if (prev != nullptr)
            prev->right = root;
        prev = root;
        if (head == nullptr)
            head = root;

        inOrder(root->right);
    }
};

int main() {

}