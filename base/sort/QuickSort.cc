#include <iostream>

template <typename T> void quick_sort_recursive(T arr[], int start, int end) {
    //参数有误直接返回
    if (start >= end)
        return;
    // 决定基准元素为每个数组的末尾元素
    T pivot = arr[end];
    // 要遍历到范围
    int left = start, right = end - 1;
    // 循环遍历条件为left<right
    while (left < right) {
        // 在数组中从左往右搜索到第一个不小于pivot的元素
        while (arr[left] < pivot && left < right)
            left++;
        // 在数组中从右往左搜索到第一个小于pivot的元素
        // 若从右开始未找到比pivot小到数则会一直搜索到与从左边找到比pivot大到数相遇
        // 这时left=right，跳出这个循环
        while (arr[right] >= pivot && left < right)
            right--;
        std::swap(arr[left], arr[right]);
    }

    // 比较相遇点数于开始指定到末尾目标数：
    // 若相遇点的数比目标数大则说明目标数的左边有比其大的数
    // 交换后目标数完成排序（左边都比它小，右边都比它大）
    //
    // 若相遇点的数比目标数小则说明目标数的左边都比其小，不需要做交换
    // 这时left应该在目标数的右边一位，left++意为将原本分治的地方设置为最末尾到最大数
    // 只需要对左边部分数组进行排序
    if (arr[left] >= arr[end])
        std::swap(arr[left], arr[end]);
    else
        left++;

    // 此时left右边的元素全部比left大，左边的元素全部比left小
    // 于是对left两边到子数组再次递归调用排序算法：分治
    quick_sort_recursive(arr, start, left - 1);

    quick_sort_recursive(arr, left + 1, end);
}
template <typename T> void quick_sort(T arr[], int len) { quick_sort_recursive(arr, 0, len - 1); }

int main() {
    // int arr[] = {61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62, 30};
    int arr[] = {3, 2, 1, 4};

    int len = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, len);
    for (auto i : arr) {
        std::cout << i << " ";
    }
    return 0;
}