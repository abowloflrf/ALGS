# 230.二叉搜索树中第 K 小的元素

中序遍历后取低 k 大的数，不过注意没有必要遍历整棵数，也不需要一个 vector 去存储，只需要一个 int 计数器，中序遍历到第 n 个是直接 return 结果