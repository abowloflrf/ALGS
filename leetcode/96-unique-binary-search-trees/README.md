# 96.不同的二叉搜索树

BST：左节点比根节点小，右节点比根节点大，且所有子树均满足

-   `G[n]` 代表 1-n 共 N 个数字最多可以组成的不同 BST 数目，**本题结果应为 `G[n]`**
-   `F[i, n]` 代表 root 为 i 时，1-n 个数字最多可以组成的不同 BST 数目
-   `F[i ,n] = G[i-1]*G[n-i]` root 为 i 时，左右分别两个结果，两个结果有相乘结果的组合
-   `G[n] = F[1,n] + F[2,n] + ... + F[n,n]`
-   即 `G[n] = (G[0]*G[n-1]) + (G[1]*G[n-2]) + ... + (G[n-1]*G[0])`