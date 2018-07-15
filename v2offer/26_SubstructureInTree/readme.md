# 树的子结构

给定两颗二叉树 A、B，判断 B 是不是 A 的子结构。

注意到这里和 LeetCode 的[572. Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree)不太一样，本题是判断**子结构**，即树 B 在树 A 的中间一部分出现即可，而不需要一直到数 A 的叶子节点都相等。LeetCode 中要求的是子树，则需要一直判断到树 A 的叶子节点。

## 判断子结构

其中两个数根的节点值相等是调用的递归函数是判断b是否是a的上面一部分：

```cpp
bool bIsTopPartOfA(BinaryTreeNode *treeA, BinaryTreeNode *treeB) {
    if (treeB == nullptr) return true;
    if (treeA == nullptr) return false;
    bool isSame = treeA->data == treeB->data;
    return isSame && bIsTopPartOfA(treeA->lchild, treeB->lchild) &&
           bIsTopPartOfA(treeA->rchild, treeB->rchild);
}
```

## 判断子树

两棵树的完整结构都必须一样：

```cpp
bool isSameTree(TreeNode *treeA, TreeNode *treeB) {
    if (treeA == nullptr || treeB == nullptr)
        return treeA == nullptr && treeB == nullptr;
    bool isSame = treeA->val == treeB->val;
    return isSame && isSameTree(treeA->left, treeB->left) &&
            isSameTree(treeA->right, treeB->right);
}
```