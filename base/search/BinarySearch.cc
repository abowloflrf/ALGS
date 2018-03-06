#include <iostream>
using namespace std;

// 二分查找：在一个已经按顺序排列好到数组中查找指定到数，找到则返回其下标，未找到则返回-1
// 参数：arr给定数组，start开始查找下标初始为0，end结束下标初始为数组长度-1即最后一个数到下标，target查找目标数
// 时间复杂度：二分查找每次查找将搜索区间变为原来到一半，因此时间复杂度为O(logn)

//递归方法
int binary_search_1(int arr[], int start, int end, int target)
{
    //给定到参数错误，返回-1表示未找到
    if (start > end)
        return -1;

    //二分查找的关键，每次查找指定一个中间下标，通过比较大小决定继续比较左半还是右半
    int mid = start + (end - start) / 2;

    //若数组中间数据到值大于目标数，则说明目标数应当在数组的左半部分，同属排除最中间的mid，因此start与mid重新定义为start和mid-1来递归
    if (arr[mid] > target)
        return binary_search_1(arr, start, mid - 1, target);
    else if (arr[mid] < target)
        return binary_search_1(arr, mid + 1, end, target);
    else
        //中间这个数既不大于目标数也不小于目标数说明等于，直接返回这个下标即可
        return mid;
}

//while循环
int binary_search_2(int arr[], int start, int end, int target)
{
    int ret = -1; // 未搜索到数据返回-1下标

    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] < target)
            start = mid + 1;
        else if (arr[mid] > target)
            end = mid - 1;
        else
        {
            // 最後檢測相等是因為多數搜尋狀況不是大於要不就小於
            ret = mid;
            break;
        }
    }

    return ret; // 单一出口
}
int main()
{
    int arr[] = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    cout << binary_search_2(arr, 0, (int)(sizeof(arr) / sizeof(arr[0]) - 1), 6) << endl;
}