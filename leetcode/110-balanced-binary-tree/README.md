# 110. 平衡二叉树

平衡二叉树：所有节点的左右子树的高度差不超过 1

## 方法一：自顶向下每个节点递归调用计算高度 `O(n^2)`

定义 `height` 方法，递归计算传入节点的树的高度，有大量重复计算

```c++
class Solution {
  public:
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        return (abs(height(root->left) - height(root->right)) <= 1) && isBalanced(root->left) &&
               isBalanced(root->right);
    }

  private:
    // 直接返回树的高度
    int height(TreeNode *root) {
        if (!root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};
```

## 方法二：剪枝

`height` 方法中先分别递归调用计算两个子树的高度，用于判断到该树是否平衡，若不平衡直接返回 -1

```c++
class Solution {
  public:
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        return height(root) != -1;
    }

  private:
    // 返回树的高度，若左右不平衡，直接返回-1
    int height(TreeNode *root) {
        if (!root)
            return 0;
        int left = height(root->left);
        if (left == -1)
            return -1;
        int right = height(root->right);
        if (right == -1)
            return -1;
        if (abs(left - right) <= 1)
            return max(left, right) + 1;
        return -1;
    }
};
```
