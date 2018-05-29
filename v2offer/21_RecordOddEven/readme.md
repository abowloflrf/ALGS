# 将一个整数数组按照奇数偶数分成两个部分

给定一串整数数组，要求设计一个算法将这个数组的奇数与偶数分离开来，要求空间复杂度为O(1)，即不使用额外的空间。

## Solution

可以定义两个指针，分别指向这个数组的首部与尾部，然后两头同时开始向中间进行遍历，由于要分开，相当于结果数组的前半部分是奇数，后半部分都是偶数。因此在头部找到第一个偶数，尾部找到第一个奇数时，两者数据进行一次交换。然后继续向中间遍历，直到两个指针相遇，此时的指针应该就为源数组的奇数偶数的分界线。