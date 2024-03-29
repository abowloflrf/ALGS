/* C++ program to print level order traversal using STL */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// A Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Iterative method to find height of Bianry Tree
void printLevelOrder(Node *root) {
    if (root == NULL)
        return;

    // 将父节点暂时储存到队列中
    queue<Node *> q;
    q.push(root);
    vector<vector<Node *>> v;
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}

// Utility function to create a new tree node
Node *newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}
