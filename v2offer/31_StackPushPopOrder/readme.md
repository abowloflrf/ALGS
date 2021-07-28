# 栈的压入，弹出顺序

给定两个整数序列，第一个表示栈的压入顺序，判断第二个是否为该栈的弹出顺序，假设压入栈的所有数字均不相等

Same as: https://leetcode-cn.com/problems/validate-stack-sequences/

题目注意点：

1. 两个序列仅是 push 和 pop 的**顺序**，并不是连续执行 push 后再指定 pop，即 push pop 可交替执行
2. 序列的值均不相等

思路：

1. 声明一个临时的 stack 模拟行为
2. 第一步 stack 为空因此只能是 push
3. 当 stack push 后的 top 和 pop 序列的头部相等时，即为一次弹出