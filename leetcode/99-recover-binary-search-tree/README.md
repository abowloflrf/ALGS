# 99. 恢复二叉搜索树

## 方法一

中序遍历，找到错误的位置然后交换值

-   若有一个降序对，说明该对需要交换
-   若有两个降序对，说明第一对的前一个和第二对的后一个需要交换

## 方法二

TODO: Morris 遍历