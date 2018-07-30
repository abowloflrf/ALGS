# 第一次只出现一次的字符

首先遍历一遍，使用map保存每个字符出现的次数。然后遍历第二遍找到第一个只出现一次的位置然后返回。

这里使用unrodered_map没有太大必要且略慢了点，由于我们要储存的是字符与个数的对应，可以直接使用一个128长度的int数组，可以保存下ASCII下所有字符的个数，且由于数组是连续的，每次访问的时间复杂度均为O(1)，比使用STL中的map更加高效。