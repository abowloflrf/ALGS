#include <iostream>
using namespace std;

class BinaryTreeNode {
   public:
    int data;
    BinaryTreeNode *lchild, *rchild;
    BinaryTreeNode(int val) {
        this->data = val;
        this->rchild = this->lchild = nullptr;
    }
};

bool bIsTopPartOfA(BinaryTreeNode *treeA, BinaryTreeNode *treeB) {
    if (treeB == nullptr) return true;
    if (treeA == nullptr) return false;
    bool isSame = treeA->data == treeB->data;
    return isSame && bIsTopPartOfA(treeA->lchild, treeB->lchild) &&
           bIsTopPartOfA(treeA->rchild, treeB->rchild);
}

bool isSubTree(BinaryTreeNode *treeA, BinaryTreeNode *treeB) {
    if (treeA == nullptr) return true ? treeB == nullptr : false;
    bool result = false;
    if (treeA->data == treeB->data) result = bIsTopPartOfA(treeA, treeB);
    if (!result) result = isSubTree(treeA->lchild, treeB);
    if (!result) result = isSubTree(treeA->rchild, treeB);
    return result;
}

int main() {
    // BinaryTreeNode *treeA = new BinaryTreeNode(8);
    // treeA->lchild = new BinaryTreeNode(8);
    // treeA->rchild = new BinaryTreeNode(7);
    // treeA->lchild->lchild = new BinaryTreeNode(9);
    // treeA->lchild->rchild = new BinaryTreeNode(2);
    // treeA->lchild->rchild->lchild = new BinaryTreeNode(4);
    // treeA->lchild->rchild->rchild = new BinaryTreeNode(7);

    // BinaryTreeNode *treeB = new BinaryTreeNode(8);
    // treeB->lchild = new BinaryTreeNode(9);
    // treeB->rchild = new BinaryTreeNode(2);
    BinaryTreeNode *treeA = new BinaryTreeNode(3);
    treeA->lchild = new BinaryTreeNode(4);
    treeA->rchild = new BinaryTreeNode(5);
    treeA->lchild->lchild = new BinaryTreeNode(1);
    treeA->lchild->rchild = new BinaryTreeNode(2);
    treeA->lchild->lchild->lchild = new BinaryTreeNode(0);

    BinaryTreeNode *treeB = new BinaryTreeNode(4);
    treeB->lchild = new BinaryTreeNode(1);
    treeB->rchild = new BinaryTreeNode(2);

    bool isSub = isSubTree(treeA, treeB);

    cout << isSub << endl;
    return 0;
}