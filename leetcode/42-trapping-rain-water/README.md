# 42. 接雨水

1. 找到最高点的位置
2. 分别从左右两边双指针向中间走到最高点，并分别维护左部分和右部分的最高点，到当前点低于左或右的最高点时，结果增加
