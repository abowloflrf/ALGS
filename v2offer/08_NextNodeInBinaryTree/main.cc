#include <iostream>
#include <vector>
using namespace std;

class BinaryTreeNode {
   public:
    char data;
    BinaryTreeNode *lchild, *rchild, *parent;
    BinaryTreeNode(int val) {
        this->data = val;
        this->rchild = this->lchild = this->parent = nullptr;
    }
};

BinaryTreeNode* getNext(BinaryTreeNode* root) {
    if (root == nullptr) return nullptr;
    //若有右节点，则下一个节点是右子树的最左节点
    if (root->rchild) {
        // pRight为右子树的根节点
        BinaryTreeNode* pRight = root->rchild;
        while (pRight->lchild) pRight = pRight->lchild;
        return pRight;
    } else if (root->parent) {
        //若本身是一个左子节点则下一个节点就是父节点
        //否则向上寻找到第一个本身是左节点的节点
        BinaryTreeNode* pParent = root->parent;
        BinaryTreeNode* pCurrent = root;
        while (pParent && pParent->lchild != pCurrent) {
            pCurrent = pParent;
            pParent = pCurrent->parent;
        }
        return pParent;
    }

    //上面都未满足，则说明本身已经是最后一个节点
    return nullptr;
}

int main() {
    BinaryTreeNode* root = new BinaryTreeNode('a');

    BinaryTreeNode* nodeB = root->lchild = new BinaryTreeNode('b');
    nodeB->parent = root;
    BinaryTreeNode* nodeC = root->rchild = new BinaryTreeNode('c');
    nodeC->parent = root;

    BinaryTreeNode* nodeD = nodeB->lchild = new BinaryTreeNode('d');
    nodeD->parent = nodeB;
    BinaryTreeNode* nodeE = nodeB->rchild = new BinaryTreeNode('e');
    nodeE->parent = nodeB;

    BinaryTreeNode* nodeH = nodeE->lchild = new BinaryTreeNode('h');
    nodeH->parent = nodeE;
    BinaryTreeNode* nodeI = nodeE->rchild = new BinaryTreeNode('i');
    nodeI->parent = nodeE;

    BinaryTreeNode* nodeF = nodeC->lchild = new BinaryTreeNode('f');
    nodeF->parent = nodeC;
    BinaryTreeNode* nodeG = nodeC->rchild = new BinaryTreeNode('g');
    nodeG->parent = nodeC;

    BinaryTreeNode* next = getNext(nodeF);
    cout << next->data << endl;
    return 0;
}