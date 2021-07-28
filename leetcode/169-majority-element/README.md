# 169. majority element

三种思路

## 哈希表计数

时间：O(N)
空间：O(N)

## 排序

时间：O(logN)
空间：O(N)

## *投票算法

时间：O(N)
空间： O(1)

遍历过程中变化 candidate，与 candidate 出现次数 count，假设第一位是 candidate，若相同则 count++，否则 count--，当 count = 0 时更换 candidate，若有多数元素，则最终留下的元素一定为最后 count > 0 的 candidate