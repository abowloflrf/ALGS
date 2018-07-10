#include <iostream>
#include <vector>
using namespace std;

class BinaryTreeNode {
   public:
    int data;
    BinaryTreeNode *lchild, *rchild;
    BinaryTreeNode(int val) {
        this->data = val;
        this->rchild = this->lchild = NULL;
    }
};

BinaryTreeNode* constructCore(int* startPreOrder, int* endPreOrder,
                              int* startInOrder, int* endInOrder) {
    //前序遍历的第一个节点就是树的根节点
    int rootData = startPreOrder[0];
    BinaryTreeNode* root = new BinaryTreeNode(rootData);

    //树只有一个节点
    if (startPreOrder == endPreOrder) {
        if (startInOrder == endInOrder)
            return root;
        else {
            cout << "Invalid Input" << endl;
            exit;
        }
    }

    //在中序中找到根节点
    int* rootInOrder = startInOrder;
    while (rootInOrder <= endInOrder && *rootInOrder != rootData) rootInOrder++;
    //在中序中未找到根节点则抛出错误
    if (rootInOrder == startInOrder && *rootInOrder != rootData) {
        cout << "Invalid Input" << endl;
        exit;
    }

    int leftLength = rootInOrder - startInOrder;  //左子树长度
    int* leftPreOrderEnd = startPreOrder + leftLength;  //前序中左子树结束指针

    //左子树长度大于0则构建左子树
    if (leftLength > 0) {
        root->lchild = constructCore(startPreOrder + 1, leftPreOrderEnd,
                                     startInOrder, rootInOrder - 1);
    }

    //右子树商都大于0则构建右子树
    if (leftLength < endPreOrder - startPreOrder) {
        root->rchild = constructCore(leftPreOrderEnd + 1, endPreOrder,
                                     rootInOrder + 1, endInOrder);
    }

    return root;
}

BinaryTreeNode* construct(int* preOrder, int* inOrder, int length) {
    if (preOrder == NULL || inOrder == NULL || length == 0) return NULL;

    return constructCore(preOrder, preOrder + length - 1, inOrder,
                         inOrder + length - 1);
};

int main() {
    int preOrder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inOrder[] = {4, 7, 2, 1, 5, 3, 8, 6};
    int length = 8;
    BinaryTreeNode* root = construct(preOrder, inOrder, length);
    return 0;
}
