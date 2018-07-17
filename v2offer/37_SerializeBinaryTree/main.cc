//
// Created by ruofeng on 2018/7/17.
//
#include <vector>
#include <iostream>
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
class Solution {
  public:
    vector<int> serialize(TreeNode *tree) {
        resultList.clear();
        serializeCore(tree, resultList);
        return resultList;
    }

    TreeNode *deSerialize(vector<int> inputList) {
        resultTree = nullptr;
        deSerializeCore(&resultTree, inputList);
        return resultTree;
    }
  private:
    vector<int> resultList;
    TreeNode *resultTree;
    void serializeCore(TreeNode *root, vector<int> &result) {
        if (root == nullptr) {
            result.push_back(-1);
            return;
        }
        result.push_back(root->val);
        serializeCore(root->left, result);
        serializeCore(root->right, result);
    }
    void deSerializeCore(TreeNode **tree, vector<int> &inputList) {
        if (inputList.empty())
            return;
        if (inputList.front() == -1) {
            inputList.erase(inputList.begin());
            return;
        }
        *tree = new TreeNode(inputList.front());
        inputList.erase(inputList.begin());
        deSerializeCore(&(*tree)->left, inputList);
        deSerializeCore(&(*tree)->right, inputList);
    }
};

int main() {
    TreeNode *treeA = new TreeNode(1);
    treeA->left = new TreeNode(2);
    treeA->right = new TreeNode(3);
    treeA->left->left = new TreeNode(4);
    treeA->right->left = new TreeNode(5);
    treeA->right->right = new TreeNode(6);

    vector<int> list = {1, 2, 4, -1, -1, -1, 3, 5, -1, -1, 6, -1, -1};
    Solution s;
    TreeNode *tree = s.deSerialize(list);
    return 0;
}

