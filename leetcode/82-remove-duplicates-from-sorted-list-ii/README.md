# 83. 删除排序链表中的重复元素 II

-   快慢指针
-   dummy 节点

fast 为头节点，slow=dummy 为头节点的前一个

-   `fast == fast->next`: while 中判断 fast 与 fast->next 是否相等，相等则 fast 前进一位，直到不相等，然后 slow 追上 fast
-   `fast != fast->next`: fast slow 各向前走一步
