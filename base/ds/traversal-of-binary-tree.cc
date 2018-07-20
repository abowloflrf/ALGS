#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class BinaryTreeNode {
   public:
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Traversal {
   public:
    Traversal(BinaryTreeNode *t) : tree(t) {}
    //递归前序遍历
    vector<int> preOrder() {
        result.clear();
        preOrderRecursive(tree);
        return result;
    }
    //非递归前序遍历
    vector<int> preOrderNoRecursive() {
        result.clear();
        stack<BinaryTreeNode *> s;
        BinaryTreeNode *node = tree;
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
    //递归中序遍历
    vector<int> inOrder() {
        result.clear();
        inOrderRecursive(tree);
        return result;
    }
    //非递归中序遍历
    vector<int> inOrderNoRecursive() {
        result.clear();
        stack<BinaryTreeNode *> s;
        BinaryTreeNode *node = tree;
        while (node != nullptr || !s.empty()) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            result.push_back(node->val);
            node = node->right;
        }
        return result;
    }
    //递归后序遍历
    vector<int> postOrder() {
        result.clear();
        postOrderRecursive(tree);
        return result;
    }
    //非递归后序遍历
    vector<int> postOrderNoRecursive() {
        result.clear();
        stack<BinaryTreeNode *> s;
        BinaryTreeNode *node = tree;
        BinaryTreeNode *prev = nullptr;  //上次访问的节点
        //先保存向左子树保存节点到栈中
        while (node != nullptr) {
            s.push(node);
            node = node->left;
        }
        while (!s.empty()) {
            //拿到最左子节点
            node = s.top();
            s.pop();
            if (node->right == nullptr || node->right == prev) {
                result.push_back(node->val);
                prev = node;
            } else {
                s.push(node);
                node = node->right;
                while (node) {
                    s.push(node);
                    node = node->left;
                }
            }
        }
        return result;
    }
    //层次遍历
    vector<vector<int>> levelTravesal() {
        levelResult.clear();
        if (tree == nullptr) return levelResult;
        vector<int> levelNodes;
        queue<BinaryTreeNode *> q;
        q.push(tree);  //根节点加入队列
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                BinaryTreeNode *node = q.front();
                levelNodes.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                q.pop();
            }
            levelResult.push_back(levelNodes);
            levelNodes.clear();
        }
        return levelResult;
    }

   private:
    BinaryTreeNode *tree;
    vector<int> result;
    vector<vector<int>> levelResult;
    void preOrderRecursive(BinaryTreeNode *node) {
        if (node == nullptr) return;
        result.push_back(node->val);
        preOrderRecursive(node->left);
        preOrderRecursive(node->right);
    }
    void inOrderRecursive(BinaryTreeNode *node) {
        if (node == nullptr) return;
        inOrderRecursive(node->left);
        result.push_back(node->val);
        inOrderRecursive(node->right);
    }
    void postOrderRecursive(BinaryTreeNode *node) {
        if (node == nullptr) return;
        postOrderRecursive(node->left);
        postOrderRecursive(node->right);
        result.push_back(node->val);
    }
};

//格式化打印vector内容
void printVector(vector<int> data) {
    cout << "[";
    for (vector<int>::iterator iter = data.begin(); iter != data.end();
         iter++) {
        if (iter != data.end() - 1)
            cout << *iter << "-";
        else
            cout << *iter;
    }
    cout << "]";
}
int main() {
    BinaryTreeNode *treeA = new BinaryTreeNode(1);
    treeA->left = new BinaryTreeNode(2);
    treeA->right = new BinaryTreeNode(3);
    treeA->left->left = new BinaryTreeNode(4);
    treeA->left->right = new BinaryTreeNode(5);
    treeA->right->left = new BinaryTreeNode(6);
    treeA->right->right = new BinaryTreeNode(7);
    treeA->left->left->left = new BinaryTreeNode(8);
    Traversal t(treeA);

    vector<vector<int>> levelResult = t.levelTravesal();
    cout << "Level-Order Traversal:\n";
    for (auto i : levelResult) {
        printVector(i);
        cout << endl;
    }

    cout << "Pre-Order Traversal:\n";
    printVector(t.preOrderNoRecursive());

    cout << "\nIn-Order Traversal:\n";
    printVector(t.inOrderNoRecursive());

    cout << "\nPost-Order Traversal:\n";
    printVector(t.postOrderNoRecursive());

    return 0;
}