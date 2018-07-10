# 二叉树的下一个节点

二叉树结构中每个节点除了有指向左右孩子节点的指针外，还有指向父节点的指针：

```cpp
class BinaryTreeNode {
   public:
    char data;
    BinaryTreeNode *lchild, *rchild, *parent;
    BinaryTreeNode(int val) {
        this->data = val;
        this->rchild = this->lchild = this->parent = nullptr;
    }
};
```

给定一个二叉树中的节点，要求返回按照中序遍历序列中这个给定节点的下一个节点。

若给定节点有右子节点，则下一个节点是右子树的最左节点；若无有节点则向上寻找到第一个本身是其父节点的左子节点的节点，那么下一个节点就是寻找到的该节点的父节点。
